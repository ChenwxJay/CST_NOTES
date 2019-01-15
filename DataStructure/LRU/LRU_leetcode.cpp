#include <iostream>
#include <map>
#include <unordered_map> //注意包含头文件
#include <vector>

using namespace std;

//LRU Cache实现，使用unordered_map和list实现
class LRUCache{
public:
	//构造函数
	LRUCache(int capacity):capacity(capacity){
		cout << "Create a LRU Cache!" << endl;
	}
	~LRUCache(){
		cout << "Destroy a LRU Cache!" << endl;
	}
	//get操作，根据输入参数key查找对应的值
	int get(int key){
		if(pos.find(key)!=pos.end()){ //在map查找是否存在Key对应的值所在的迭代器
             put(key,pos[key]->second);//将键值对插入到队列头
             return pos[key]->second;
		}
		return -1;
	}
	//put操作，将键值对插入LRU Cache
	void put(int key,int value){
		//需要查找键值对是否已经存在
		if(pos.find(key)!=pos.end()){
			 //已经存在，就删除
			 recent.erase(pos[key]);//通过key拿到对应键值对的迭代器，再从list中删除
		}
		else if(recent.size() >= capacity){
			//存储的键值对数量达到缓存容量，需要删除最近最少使用的键值对
			//从map中删除队列尾部的元素对应的映射
            pos.erase(recent.back().first);
			//从双向链表中删除
			recent.pop_back();
		}
		//将Key-Value键值对添加到链表中，设置map，注意是添加到队列头
		recent.push_front({key,value});
		pos[key] = recent.begin();//将队列头的迭代器设置到map中
	}
private:
	int capacity;//指定LRUCache的容量
	list<pair<int,int> > recent;
	//使用哈希表实现快速查找
    unordered_map<int,list<pair<int,int>>::iterator> pos;//value位置存储一个list的迭代器 
};