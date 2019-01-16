#include "LRU.h"

void LRU_Cache::detachNode(CacheNode* node){
	 //从双向链表中删除节点，调整前后两个节点的指针
	node->prev->next = node->next;
	nodex->next->prev = node->prev;
}
void LRU_Cache::InsertFront(CacheNode* node){
	//将新节点插入链表的头部

}

//获取值,注意LRU算法的实现
int LRU_Cache::Get(int key){
	//获取双向链表第一个节点
	CacheNode* target_node = list_head->next();
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
