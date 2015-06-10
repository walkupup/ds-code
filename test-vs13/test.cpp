#include <stdio.h>

// 在数组a中查找元素e，返回e的位置，数组长度为len
int searchList(int a[], int len, int e)
{
	int i;
	a[0] = e;
	for(i=len; a[i] != e && i > 0; --i);

	return i;
}
void main()
{
	int b=0;
	int a[5] = {1, 2, 3, 4, 5};

	b=searchList(a, 4, 3);
	if(b==0)
		printf("不存在");
	else
		printf("%d\n",b);
}