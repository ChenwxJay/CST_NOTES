#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <iostream>

using namespace std;
using namespace boost::asio;//asio命名空间声明
void handler(){

} 
int main()
{ 
  //创建一个io_service对象，负责处理读写请求
  boost::asio::io_service ioservice;
 
  steady_timer timer{ioservice, std::chrono::seconds{3}}; //创建一个I/O定时器对象
  timer.async_wait([](const boost::system::error_code &ec)
    { std::cout << "3 sec\n"; }); //异步等待
  //需要调用run函数来等待异步操作完成，并获取结果
  ioservice.run();
  return 0;
}
