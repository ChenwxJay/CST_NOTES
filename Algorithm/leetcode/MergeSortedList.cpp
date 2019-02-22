#include <iostream>
#include <list>

//列表节点结构体定义
struct ListNode
{   //存储数据，int类型
	int data;
	ListNode* next;
};
//两个有序链表合并，递归实现
class Solution{
public:
	ListNode* solve(){
	   //注意判断
       if(head_1 == nullptr)
       	  return head_2;
       if(head_2 == nullptr)
       	  return head_1;
       	//利用递归来实现有序链表的合并
       if(head_1->data <= head_2->data){ //head_1在前面
            head_1->next = solve(head_1->next,head_2);
            //递归完成立即返回
            return head_1;
       }
       else{
       	   //注意递归的函数参数
           head_2->next = solve(head_2->next,head_1);
           return head_2; //返回head_2作为新链表的头结点
       }
	}
};