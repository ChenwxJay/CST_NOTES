/*
  ���������㷨ʵ��
*/
class QuickSort{
private:
  //�ڲ�partition�㷨ʵ�� 
  int partiton(int array[],int start,int end);
public:  
  void sort(int array[],int start,int end);
}; 

//�����㷨ʵ�� 
void QuickSort::sort(int array[],int start,int end){
	if(end <= start)//�ݹ鷵�� 
	   return;
	//partition�㷨����ȡ�ָ��
	int middle = partition(array,start,end);
	//�������߷ֱ�ݹ�
	sort(array,start,middle-1);
	sort(array,middle+1,end);
}

int QuickSort::parition(int array[],int start,int end){
	int i = start,j = end + 1;
	int temp = array[start];
	//ѭ�����з��飬��tempС�ķ�����ߣ���temp��ķ����ұ�
	while(true){
		//����߿�ʼɨ�� 
		while(array[i] < temp && i <=end){
			i++;
		}
		//���ұ߿�ʼɨ�� 
		while(array[j] > temp && j >= start){
			j--;
		}
		if(i >= j)
		  break;
		swap(nums,i,j);//��������λ�� 
	}
	//����ٽ������ƶ������ʵ�λ��
	swap(nums,start,j);
	return j;
}
