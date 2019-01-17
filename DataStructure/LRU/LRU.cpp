#include "LRU.h"
using namespace std;

//使用双向链表实现LRU Cache
//无论是写入数据还是查询数据，最后都需要将当前访问的数据提取到链表头，保证下一次访问可以快速访问
//缓存大小有限，最长时间没被访问的数据应该置换出缓存

LRU_Cache::LRU_Cache(int cache_size):MaxCacheSize(cache_size),count(0)
{
      //需要先创建链表的头尾节点，此时是空链表
	  list_head = new CacheNode();
	  list_tail = new CacheNode();
	  //设置指针
	  list_head->prev = nullptr;
	  list_head->next = list_tail;
	  list_tail->prev = list_head;
	  list_tail->next = nullptr;
}
LRU_Cache::~LRU_Cache(){
	//需要析构所有链表节点
	CacheNode* temp = list_head->next;//从第一个存储有效数据的节点开始
	while(temp!=nullptr){
        delete temp->pre;//析构前面那个节点
        temp = temp->next;            
	}
	//析构队尾节点
	delete list_tail;
}
void LRU_Cache::detachNode(CacheNode* node){
	 //从双向链表中删除节点，调整前后两个节点的指针
	node->prev->next = node->next;
	nodex->next->prev = node->prev;
}
void LRU_Cache::InsertFront(CacheNode* node){
	//将新节点插入链表的头部
    node->next = list_head->next;//设置后向指针
    list_head->next->pre = node;
    node->pre = list_head;
    list_head->next = node;//设置头节点与插入新节点的关系
}

//获取值,注意LRU算法的实现
int LRU_Cache::Get(int key){
	//获取双向链表第一个节点
	CacheNode* target_node = list_head->next;
	//while循环遍历
	while(target_node->next != nullptr){
		//每一个节点都去匹配，判断是否为所要查找的节点
		if(target_node->key == key){
			//从当前位置删除，再插入到链表头部
			detachNode(target_node);
			InsertFront(target_node);
			return target_node->value;//查找到节点，返回对应键值对的值
		}
		target_node = target_node->next;//切换到下一个节点
	}
	return -1;
}
//插入操作,需要先判断键值对是否已经存在，是就更新，否则根据当前Cache容量与最大容量是否相等决定是否需要淘汰，再插入新节点
bool LRU_Cache::Put(int key,int value)
{
	CacheNode* temp = list_head->next;//获取双向链表头结点
	//循环遍历链表，判断是否已经存在键
	while(temp->next != nullptr)
	{
		if(temp->key == key)
		{   //如果已经存在键值对，就更新该键值对的值，并将该键值对移动到链表头，表示最近访问过
			temp->value = value;
			Get(value);
			return true;
		}
	}
	//如果没有返回，表示链表中没有已经存在的键值对
	if(this->count >= MaxCacheSize){
		cout << "The size of LRU Cache overloads!" << endl;
		//需要删除双向链表最后的节点
		temp = list_tail->pre;
		temp->pre->next = list_tail;//设置后向指针
		list_tail->pre = temp->pre;
		delete temp;//需要调用析构函数，手动delete
	}

	//构建新节点
	CacheNode * new_ = new CacheNode();
	assert(new_ != nullptr);
	//填充数据
 	new_->key = key;
    new_->value = value;

    //实际大小加1
    this->count++;
    return true;
}
void LRU_Cache::PrintAllNodes(){
        CacheNode* temp = list_head->next;
        while(temp->next != nullptr)
        {
        	cout << "key:" << temp->key << ",value: " << temp->value << endl;
        	temp = temp->next;
        }
        coutr << endl;
}