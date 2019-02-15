#include <iostream>
#include <memory>
#include <array> //C++11开始有的头文件
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio::ip::tcp;

class Session:public std::endable_shared_from_this<session>{
public:
    Session(tcp::socket sock):socket_(std::move(sock)){
    	cout << "Create a session!" << endl;
     }
    void start(){ //开启一个会话
    	async_read();
    }
private:
	void async_read(){
		auto self(shared_from_this());
		//套接字读写
		socket_.async_read_some(boost::asio::buffer(data_), //利用数据data构建缓冲区
			[this,self](const boost::system::error_code& ec,size_t bytes_transferred)//给读绑定回调
			{   
				if(!ec){//只要没有发生错误
					async_write(bytes_transferred);//采用异步写
				}
			});
	}
	//异步写函数
	void async_write(std::size_t length){
       auto self(shared_from_this());
       //异步写，需要操作缓冲区
       boost::asio::async_write(socket_,boost::asio::buffer(data_,length),
       	[this,self](const boost::system::error_code& ec,size_t len){
       		if(!ec)
       			async_read();
       	});
	}
	//会话内部的socket,会话基于socket
	tcp::socket socket_;
	//底层数据缓冲区，使用array存储
	std::array<char,1024> data_;
};
//服务器类，使用asio提供的类和API实现
class Server{
private:
	void async_accept(){
		//调用内部acceptor对socket进行监听，并实现异步accept,一旦socket连接建立，就调用第二个参数传入的回调函数
        acceptor_.async_accept(socket_,std::bind(&server::handle_accept(),this,
        	std::placeholders::_1));
	}
	void handle_accept(){
		if(!ec){
           std::shared_ptr<Session>(new Session(std::move()))
		}
	}
public:
	//构造函数，需要初始化内部
	Server(boost::asio::io_service & io_Service,int port)
	      :acceptor_(io_Service,tcp::endpoint(tcp::v4(),port)),socket_(io_Service)
	{   
		cout << "The server is starting...." << endl;
	}


}