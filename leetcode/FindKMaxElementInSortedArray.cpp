#include <iostream>
#include <vector>
using namespace std;

//快速排序是对冒泡排序的改进，降低冒泡排序的复杂度
//这里不用完全实现快排
class Solution{
private:
	int sort(std::vector<int> v,int begin,int end)
	{
        if(end < begin)
        	return -1;
        int key = array[begin];//获取第一个元素作为标志
        while(begin < end){
        	while(array[end] > key && begin < end)
        		end--;
        	array[begin] = array[end];//较小的数据交换到前面的位置
        	while()
        }
	}
public:
    int kMaxElement(vector<int>& array,int begin,int end,int k)
    {
    	if(end > begin)//递归终止条件
    		return -1;
    	//partition分组，获取一个局部有序的数组
    	int index = sort(array,begin,end);
    	//判断哨兵位置与k-1的大小关系
    	if(index == k-1){
    		//找到第K大的数字
    		return array[index];//直接返回
    	}
    	else if(index < k-1){
    		//右递归，只对右边进行递归
    		return kMaxElement(array,index + 1,high,k);
    	}
    	else{
            //左递归，只对左边进行递归
            return kMaxElement(array,begin,index-1,k);
    	}
    	return -1;//找不到就返回-1
    }
};