#include <stdio.h>

// ������a�в���Ԫ��e������e��λ�ã����鳤��Ϊlen
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
		printf("������");
	else
		printf("%d\n",b);
}