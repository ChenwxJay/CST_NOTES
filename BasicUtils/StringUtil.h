#ifndef STRING_UTIL_H
#define STRING_UTIL_H

//strcmp函数实现
//注意函数参数是两个const char*,指向两个字符串
int strcmp(const char* str1,const char* str2)
{
	if(str1 == NULL || str2 == NULL)
	    return -1;//返回-1，表示错误
	//循环遍历比较
	while((*str1 == *str2) && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return *str1-*str2;//返回最终停止位置的字符值之差
}

//字符串拷贝
char* strcpy(char* dest,const char* src);
//字符串拷贝
char* strcat(char* dest,const char* src);
//字符串拷贝
char* strncpy(char* dest,const char* src);
#endif

