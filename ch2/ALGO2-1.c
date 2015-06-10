 /* algo2-1.c 实现算法2.1的程序 */
 #include"c1.h"
 typedef float ElemType;
 #include"c2-1.h" /* 采用线性表的动态分配顺序存储结构 */
 #include"bo2-1.c" /* 可以使用bo2-1.c中的基本操作 */

 Status equal(ElemType c1,ElemType c2)
 { /* 判断是否相等的函数，Union()用到 */
   if(c1==c2)
     return TRUE;
   else
     return FALSE;
 }

 void Union(SqList *La,SqList Lb) /* 算法2.1 */
 { /* 将所有在线性表Lb中但不在La中的数据元素插入到La中 */
   ElemType e;
   int La_len,Lb_len;
   int i;
   La_len=ListLength(*La); /* 求线性表的长度 */
   Lb_len=ListLength(Lb);
   for(i=1;i<=Lb_len;i++)
   {
     GetElem(Lb,i,&e); /* 取Lb中第i个数据元素赋给e */
     if(!LocateElem(*La,e,equal)) /* La中不存在和e相同的元素,则插入之 */
       ListInsert(La,++La_len,e);
   }
 }

 void print(ElemType *c)
 {
   printf("%f ",*c);
 }

 void main()
 {
	 ElemType a;
	 SqList L;
	 InitList(&L);
	 ListInsert(&L, 1, 3.3);
	 ListInsert(&L, 1, 2.2);
	 ListInsert(&L, 1, 1.1);
	 ListTraverse(L, print);
	 ListDelete(&L, 1, &a);
	 ListTraverse(L, print);
 }





 void main2()
 {
	SqList L;
	ElemType a;
	InitList(&L);
	ListInsert(&L, 1, 3.3);
	ListInsert(&L, 1, 2.2);
	ListInsert(&L, 1, 1.1);
	ListTraverse(L, print);
	ListDelete(&L, 1, &a);
	ListTraverse(L, print);

 }


 void main1()
 {
   SqList La,Lb;
   Status i;
   int j;
   i=InitList(&La);
   if(i==1) /* 创建空表La成功 */
     for(j=1;j<=5;j++) /* 在表La中插入5个元素 */
       i=ListInsert(&La,j,j);
   printf("La= "); /* 输出表La的内容 */
   ListTraverse(La,print);

   int k;
   for (j = 1; j <= 2; j++) /* 在表La中插入5个元素 */
	   i = ListDelete(&La, j, &k);
   ListTraverse(La, print);
   return;


   InitList(&Lb); /* 也可不判断是否创建成功 */
   for(j=1;j<=5;j++) /* 在表Lb中插入5个元素 */
     i=ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* 输出表Lb的内容 */
   ListTraverse(Lb,print);
   Union(&La,Lb);
   printf("new La= "); /* 输出新表La的内容 */
   ListTraverse(La,print);
 }