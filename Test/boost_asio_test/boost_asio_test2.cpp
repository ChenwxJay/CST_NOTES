#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
using namespace std;
using namespace boost;

//全局io服务对象，方便使用多线程
boost::asio::io_service service;

void handler(const boost::system::error_code &ec)//函数参数是错误码对象的引用，需要在函数内处理
{ 
  //函数参数为错误码
  std::cout << "5s" << std::endl; 
} 

void thread_run(){
	service.run();//调用全局的io_service的run方法，可以处理多个handler
}

void thread_test(){
   boost::asio::deadline_timer timer1(service, boost::posix_time::seconds(5)); 
   timer1.async_wait(handler);
   boost::asio::deadline_timer timer2(service, boost::posix_time::seconds(5)); 
   timer2.async_wait(handler);
   //创建两个线程，使用boost提供的C++ thread
   //两个线程均调用同一io_service的run方法，因此可以同时处理两个定时器的handler
   boost::thread thread1(thread_run);
   boost::thread thread2(thread_run);

   //需要等待线程结束
   thread1.join();
   thread2.join();
}
//指定一个定时器，定时到期之后执行
int main(){
	//测试单线程调用run
	boost::asio::io_service io_service;
	//创建一个定时器，指定截止时间
	boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
	//函数参数是处理器
	cout << "async_wait" << endl;
	timer.async_wait(handler); //这里不会阻塞，函数立即返回
    cout << "register a handler for handle time event!" << endl;
    //需要在io服务中等待
    io_service.run();  //run函数是阻塞的，只有执行完handler才会返回
    cout << "finished!" << endl;
    
    //多线程调用同一个io服务的run方法，同时处理多个handler
    cout << "multi thread" << endl;
    thread_test();
    return 0;
}
