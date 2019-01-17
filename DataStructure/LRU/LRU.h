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
public:
	//构造函数，默认大小为10
	LRU_Cache(int size = 10);
	~LRU_Cache();

	//查询函数
	int Get(int key);
	//插入新的键值对，或者更新已有的键值对
	void Put(int key,int value);
	//辅助函数
	void PrintAllNodes();
private:
	int count;//cache实际长度
	int MaxCacheSize;
    CacheNode* list_head;//链表头结点
    CacheNode* list_tail;
};

#endif
