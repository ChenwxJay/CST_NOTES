#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<vector<int>>& array){
	int m = array.size();//多少行
	if(m == 0)
		return 0;
	int n = array[0].size();//多少列
	if(n == 0)
		return 0;
	//创建一个二维数组，存储最大矩形的边长
	vecotr<vector<int> > sum;
	//初始化第一行和第一列
	for(int i = 0;i < m;i++){ //第一列
		sum[i][0] = array[i][0];
	} 
	for(int j = 0;j < n;j++){
		sum[0][j] = array[0][j];
	}
	//循环计算每个sum[i][j]的值，代表以array[i][j]为右下角，全部为1，边长最长的正方形边长
	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;i++){
			if(array[i][j] == 1){
				 //考虑三个情况的最小值
                 sum[i][j] = min(array[i][j-1],array[i-1][j],sum[i-1][j-1]) + 1;
			}
			else{
				 sum[i][j] = 0;
			}
		}
	}
	//循环求出sum数组中最大的那个值，即为最大正方形的边长
	int max_square_length = sum[0][0];
	//int i = 0;
	//int j = 0;
	for(int )


}
int main(){
	
}