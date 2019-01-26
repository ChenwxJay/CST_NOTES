#include <iostream>
#include <stack>
#include <functional>
#include <exception>
using namespace std;
//两个栈实现一个队列，使用STL组件
class StacksForQueue{
private:
	//底层包含了两个STL的栈对象，注意模板参数
	stack<int> stack1;
	stack<int> stack2;
public:
    //实现队列提供的方法
    void push(int value){
    	//直接压入栈1
        stack1.push(value);
    }
    //从队头删除元素
    int pop(){
        //首先校验两个栈是否都为空
        if(stack1.empty() && stack2.empty()){
        	  //队列没有数据，直接抛出异常
              throw new exception();
        }
        //如果栈2不为空，则直接pop出栈2的栈顶元素，即队头元素
        if(!stack2.empty()){
        	return stack2.pop();
        }
        //栈2为空，则需要将栈1的数据pop出来，再push到栈2，再返回

        if(stack1.size() == 1) //只有一个元素，直接pop并返回即可
        	return stack1.pop();
        //循环处理
        while(!stack1.empty()){
        	//从栈1pop出数据，然后将数据push到栈2
        	stack2.push(stack1.pop());
        }
        //最后需要对栈2进行pop,获取栈顶元素，相当于获取队列头元素
        return stack2.pop();
    }
};
//两个队列实现一个栈
class QueuesForStack{
public:
	queue<int> queue1;
	queue<int> queue2;
}
int main(){

}