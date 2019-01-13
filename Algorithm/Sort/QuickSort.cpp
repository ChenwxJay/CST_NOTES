/*
  快速排序算法实现
*/
class QuickSort{
private:
  //内部partition算法实现 
  int partiton(int array[],int start,int end);
public:  
  void sort(int array[],int start,int end);
}; 

//排序算法实现 
void QuickSort::sort(int array[],int start,int end){
	if(end <= start)//递归返回 
	   return;
	//partition算法，获取分割点
	int middle = partition(array,start,end);
	//左右两边分别递归
	sort(array,start,middle-1);
	sort(array,middle+1,end);
}

int QuickSort::parition(int array[],int start,int end){
	int i = start,j = end + 1;
	int temp = array[start];
	//循环进行分组，比temp小的放在左边，比temp大的放在右边
	while(true){
		//从左边开始扫描 
		while(array[i] < temp && i <=end){
			i++;
		}
		//从右边开始扫描 
		while(array[j] > temp && j >= start){
			j--;
		}
		if(i >= j)
		  break;
		swap(nums,i,j);//交换两个位置 
	}
	//最后再将轴心移动到合适的位置
	swap(nums,start,j);
	return j;
}
