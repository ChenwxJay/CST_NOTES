#ifndef LRU_H
#define LRU_H

//定义节点数据结构
typedef struct Node{
	int key;//键
	int value;//值

	struct Node* next;//指向下一个节点
	struct Node* prev;//指向上一个节点
}CacheNode;
//LRU Cache类声明
class LRU_Cache{
	//构造函数，默认大小为10
	LRU_Cache(int size = 10);
	~LRU_Cache();
}