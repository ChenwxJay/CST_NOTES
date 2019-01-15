//二分查找,使用非递归方式实现，基于循环 

int BinarySearch(int array[],int start,int end,int target){
	if(array == nullptr)//校验传入的数组是否满足条件 
	    return -1; 
	//循环，进行二分
	int middle = 0;
	while(start <= end) 
	{  
	   //每次循环计算当前范围内的中间节点 
	   middle = (start+end)/2;
	   if(array[middle] == target)
	      return middle;
	   else if(array[middle] >= target)
	      end = middle - 1;
	   else
	      start = middle + 1;
    }//循环退出表示没有找到
	return -1; 
} 
