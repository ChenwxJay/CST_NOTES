//���ֲ���,ʹ�÷ǵݹ鷽ʽʵ�֣�����ѭ�� 

int BinarySearch(int array[],int start,int end,int target){
	if(array == nullptr)//У�鴫��������Ƿ��������� 
	    return -1; 
	//ѭ�������ж���
	int middle = 0;
	while(start <= end) 
	{  
	   //ÿ��ѭ�����㵱ǰ��Χ�ڵ��м�ڵ� 
	   middle = (start+end)/2;
	   if(array[middle] == target)
	      return middle;
	   else if(array[middle] >= target)
	      end = middle - 1;
	   else
	      start = middle + 1;
    }//ѭ���˳���ʾû���ҵ�
	return -1; 
} 
