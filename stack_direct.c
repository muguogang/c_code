#include <stdio.h>

//堆栈的开口方向测试：1.向地址增大的方向增加，2向地址减小的方向增加；
//buf的生长方向和栈的开口方向没有关系；
//buf的方向永远是地址增大的方向；

int main(void)
{
	int a;
	int b;
	char buf[128]; //
	
	//如果b的地址大于a的地址，则是第1种属性，反之，则是第2种属性
	printf("&a:%d, &b:%d\n",&a, &b);

	return 0;	
}
