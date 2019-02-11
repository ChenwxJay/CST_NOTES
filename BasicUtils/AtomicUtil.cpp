#include <atomic>
#include <iostream>
#include <memory>

//使用C++11提供的原子类实现原子指针类
class AtomicPointer{
private:
	//atomic是一个模板类，参数使用void*,接受任何类型的指针
	std::atomic<void*> rep_;
public:
	AtomicPointer() = default;//默认构造函数
	AtomicPointer(void* v):rep_(v)
	{   //显式构造函数，使用原生指针直接构造rep
		cout << "AtomicPointer" << endl;
	}
	void* Acquire_load() const{
	   //利用底层atomic对象的load方法，指定内存顺序
       return rep_.load(std::memory_order_acquire);
	}
	//设置函数，参数是一个原生指针
	void Release_store(void* v){
       rep_.store(v,std::memory_order_release);
	}
	//不加同步的获取和设置
	inline void* NoBarrier_Load(){
		return rep_.load(std::memory_order_relaxed);
	}
	
} 