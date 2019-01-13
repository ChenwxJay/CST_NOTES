//插入排序实现

/*
基本思想:每次都将当前元素插入到左侧已经排序的数组中，使得插入之后左侧数组依然有序
复杂度：插入排序的复杂度取决于数组的初始顺序，如果数组已经部分有序了，逆序较少，那么插入排序会很快 
*/ 
class InsertSort{
public:
   void sort(int num[],int start,int end){
   	  int i = start,j = end;
   	  int len = end - start;
   	  for(i = start+1;i <= end;i++){//i每前进一次，代表左边已经有序的数组元素增加一个 
   	    //从i位置向前比较，看是否有逆序对 
		for(j = i;j > 0;j--){
   	       if(num[j] < num[j-1]){
   	         swap(num,j,j-1); 	
		  } 	
		}	
	  }
   }
}; 
