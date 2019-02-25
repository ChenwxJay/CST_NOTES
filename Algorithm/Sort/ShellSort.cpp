#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ShellSort(vector<int>& temp){
   if(temp.empty())
   	   return;
    int tem;
    int length = temp.size();
    int h = length;
    while(h >= 1){
    	//内部使用两层for循环进行分组，每一组使用直接插入排序
    	for(int i = h;i < temp.size();i++){ //外循环控制分组
            //内循环控制同一组内的直接插入排序
            for(int j = i;j >= h && temp[j] < temp[j - h];j -= h){ 
                   tem = temp[j - h];
                   temp[j - h] = temp[j];
                   temp[j] = tem;  //使用临时变量进行交换
            }
    	}
    	cout << "gap " << h << ":"; 
    	for(int i:temp){ //每次排序结束，打印当前排序的结果
    		cout << i << " ";
    	}
    	cout << endl;
    	//每次循环，gap减半
    	h /= 2;
    }
}
int main(){
	vector<int> array = {1,3,2,4,5,7,9,8,0,6};
	ShellSort(array);
	//排序结束，打印结果
	for (std::vector<int>::iterator iter= array.begin(); iter != array.end();iter++)
	{   //使用迭代器遍历
		cout << *iter << " ";
	}
	return 0;
}