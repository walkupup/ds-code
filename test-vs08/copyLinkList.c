 /* algo2-5.c 实现算法2.11、2.12的程序 */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h"
 #include"bo2-2.c"

 void CreateList(LinkList *L,int n) /* 算法2.11 */
 { /* 逆位序(插在表头)输入n个元素的值，建立带表头结构的单链线性表L */
   int i;
   LinkList p;
   *L=(LinkList)malloc(sizeof(struct LNode));
   (*L)->next=NULL; /* 先建立一个带头结点的单链表 */
   printf("请输入%d个数据\n",n);
   for(i=n;i>0;--i)
   {
     p=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
     scanf("%d",&p->data); /* 输入元素值 */
     p->next=(*L)->next; /* 插入到表头 */
     (*L)->next=p;
   }
 }

 void CreateList2(LinkList *L,int n)
 { /* 正位序(插在表尾)输入n个元素的值，建立带表头结构的单链线性表 */
   int i;
   LinkList p,q;
   *L=(LinkList)malloc(sizeof(struct LNode)); /* 生成头结点 */
   (*L)->next=NULL;
   q=*L;
   printf("请输入%d个数据\n",n);
   for(i=1;i<=n;i++)
   {
     p=(LinkList)malloc(sizeof(struct LNode));
     scanf("%d",&p->data);
     q->next=p;
     q=q->next;
   }
   p->next=NULL;
 }

 void MergeList(LinkList La,LinkList *Lb,LinkList *Lc)/* 算法2.12 */
 { /* 已知单链线性表La和Lb的元素按值非递减排列。 */
   /* 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列 */
   LinkList pa=La->next,pb=(*Lb)->next,pc;
   *Lc=pc=La; /* 用La的头结点作为Lc的头结点 */
   while(pa&&pb)
     if(pa->data<=pb->data)
     {
       pc->next=pa;
       pc=pa;
       pa=pa->next;
     }
     else
     {
       pc->next=pb;
       pc=pb;
       pb=pb->next;
     }
   pc->next=pa?pa:pb; /* 插入剩余段 */
   free(*Lb); /* 释放Lb的头结点 */
   Lb=NULL;
 }

 void visit(ElemType c) /* ListTraverse()调用的函数(类型要一致) */
 {
   printf("%d ",c);
 }

Status ListCount(LinkList L, ElemType e, int *count)
{
	int n = 0;
	LNode *p = L->next;

	while (p)
	{
		if (p->data == e)
		{
			n++;
		}
		p = p->next;
	}
	*count = n;
	return OK;
}

Status ListCopy(LinkList L, LinkList *L1)
{
	int n = 0;
	LNode *p = L->next;
	LNode *q, *node;
	LinkList LCopy;

	InitList(&LCopy);	// 创建新链表
	q = LCopy;

	while (p)
	{
		node = (LNode *)malloc(sizeof(LNode));	// 创建新节点
		node->data = p->data;	// 复制数据域
		q->next = node;			// 把新节点链接到新的链表末尾

		p = p->next;
		q = q->next;
	}
	q->next = NULL;				// 最后一个节点指针域为空

	*L1 = LCopy;
	return OK;
}


 void main()
 {
	int n=5;
	LinkList La, Lb;
	int data[5] = {2, 3, 3, 4, 5};
	int count;

	InitList(&La);
	ListInsert(La, 1, 2);
	ListInsert(La, 1, 3);
	ListInsert(La, 1, 3);
	ListInsert(La, 1, 4);
	ListInsert(La, 1, 5);

	// 输出链表La的内容
	printf("La="); 
	ListTraverse(La,visit);

	// 统计链表中某个值的元素个数
	ListCount(La, 4, &count);
	printf("count = %d\n", count);


	// 复制链表
	ListCopy(La, &Lb);

	// 输出链表Lb的内容
	printf("Lb="); 
	ListTraverse(Lb,visit);

	DestroyList(&La);
	DestroyList(&Lb);

	return;	

 }
