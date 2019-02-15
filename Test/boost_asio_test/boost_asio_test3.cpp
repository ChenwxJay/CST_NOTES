#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <vector>
using namespace std;

boost::asio::io_service io_service;//全局io_service对象
boost::asio::ip::tcp::resolver resolver(io_service);
//全局socket,以io_service为参数
boost::asio::ip::tcp::socket sock(io_service); 

//全局缓冲区
boost::array<char,4096> buffer;

void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred)
{   
	//根据错误码的值决定是否处理缓冲区数据
	if(!ec){
		//从缓冲区读取数据，并构造一个string对象
		cout << string(buffer.data(),bytes_transferred) << endl;
		sock.async_read_some(boost::asio::buffer(buffer), read_handler);//异步读取socket数据
	}
}
void resolve_handler(const boost::system::error_code &ec,boost::asio::ip::tcp::resolver::iterator it){
    if(!ec){
    	//调用socket的异步连接操作，需要操作指向reslover的
    	sock.async_connect(*it,connect_handler);
    }
}
void connect_handler(const boost::system::error_code &ec){
	if(!ec){
		//使用字符串常量构建缓冲区对象，并写到socket上
		boost::asio::write(sock, boost::asio::buffer("GET / HTTP 1.1\r\nHost: highscore.de\r\n\r\n"));
        //发送请求之后，对套接字进行读取，数据写到buffer缓冲区，读完调用回调函数
		sock.async_read_some(boost::asio::buffer(buffer), read_handler);
	}
}

int main(){
   //创建一个query对象，绑定一个URL,注意第二个参数是一个端口号
   boost::asio::ip::tcp::resolver::query query("www.highscore.de", "80");
   //解析，异步向服务器获取数据，一旦返回就调用解析回调函数
   resolver.async_resolve(query, resolve_handler);  

   //io服务等待异步操作完成
   io_service.run();
   return 0;
}