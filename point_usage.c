#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char buf[128]; //c可以在栈上分配内存
	char *p1 = NULL;
	char *p2 = NULL;
	int i;
	
	//不断的改变指针p1的值，让其指向栈空间的地址
	p1 = &buf[0];  
	p1 = &buf[1];

	for(i=0; i<10; i++)
	{
		p1 = &buf[i];	
	}
	
	//不断的改变指针p1的值，让其指向堆空间的地址
	p2 = (char*)malloc(10);
	if(p2 == NULL)
	{
		return -1;
	}
	for(i=0; i<10; i++)
	{
		p1 = p2+i;
	}

	if(p2 != NULL)
	{
		free(p2);
		p2 = NULL; //防止p2成为野指针
	}
	return 0;
}



/*
//NULL地址不能被使用
int main(void)
{
	char* p = NULL;

	strcpy(NULL, "ABDCE");

	return 0;
}
*/
