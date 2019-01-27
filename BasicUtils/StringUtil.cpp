char* strcpy(char* dest,const char* src)
{
	//异常检测，检查dest和src是否为空
	if(dest == nullptr || src == nullptr)
		return nullptr;
	//先检查源指针和目的指针是否相等，相等则不用拷贝
	if(dest == src)
		return dest;
	//拷贝，需要考虑重叠
}
//字符串连接函数
char* strcat(char* dest,const char* src){
	//异常检测，检查dest和src是否为空
	if(dest == nullptr || src == nullptr)
		return dest; //直接返回目标指针
	//获取当前字符串结尾字符位置
	int length = strlen(dest);
	//将源字符串拷贝到目标字符串之后，从空字符开始覆盖
	char* temp = dest + length;
    //循环拷贝，注意终止条件
	while((*temp++ = *src++)!='\0');//已经补上空字符，直接返回

	//返回源字符串的首地址
	return dest;
}

//简易版atoi函数实现，不考虑数值越界等异常情况
int atoi(const char* str){
	assert(str != nullptr);
    
}