#include <iostream>
#include <vector>
using namespace std;
//连续数组最大子数组和，数组元素有正有负
int FindTheSumOfTheSubArray(vector<int>& array){
    if(array.size() == 0)
    	return 0;
    int max = -1000000;
    int cur_sum = 0;
    //循环遍历整个数组，O(n)复杂度
    for(int i = 0;i <array.size();i++)
    {   //小于0，累加之后和会变小，因此舍弃
    	if(cur_sum <= 0)
    		cur_sum = array[i];//小于零则直接舍弃前面的和，从当前位置触发
    	else
    		cur_sum += array[i];
    	//更新当前最大和
    	if(max  < cur_sum)
    		max = cur_sum;
    }
    //遍历完数组就可以退出，已经找到最大值
    return max;
}
int main(){
   
}