#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//heap
//注意：return ptr 会把申请的内存的首地址返回到主调函数；
//函数返回时，局部变量ptr会被释放
//但是堆中申请的内存不会被释放,
//主调函数依然可以使用这片空间；
char* get_memery1(int num)
{
	char* ptr = NULL;

	ptr = (char*)malloc(num * sizeof(char) );
	if(ptr == NULL)
	{
		perror("get memery failed\n");
		return NULL;
	}
	return ptr;
}

//stack
//函数返回时,栈中的局部变量会被操作系统释放
//主调函数再去使用这片栈内存就是不合法的，后果不堪设想；
char* get_memery2(void)
{
	char buf[64];
	strcpy(buf, "123456789");
	printf("buf: %s\n", buf);
    //return buf;
}

int main(void)
{
	char* tmp = NULL;

	tmp = get_memery1(10);
//	tmp = get_memery2();
	if(tmp == NULL)
	{
		perror("tmp == NULL\n");
		return 0;
	}
	strcpy(tmp, "654321");
	printf("heap::tmp:%s\n", tmp);
	
	free(tmp); //don't forget it;

	return 0;
}

