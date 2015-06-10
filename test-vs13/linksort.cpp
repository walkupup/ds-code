
#include"c1.h"
typedef int ElemType;
#include"c2-2.h"
#include"bo2-2.c"

void FindMax_L(LinkList &L, int &idx, ElemType &e)
{
	int i = 1;
	LNode *p = L->next;
	e = -99999;
	idx = 0;

	while (p)
	{
		if (p->data > e)
		{
			e = p->data;
			idx = i;
		}
		p = p->next;
		i++;
	}
	return;
}

// 对L排序, 得到L1
Status ListSort_L(LinkList &L, LinkList &L1)
{
	ElemType e;
	int idx;

	InitList(&L1);
	while (L->next != NULL)
	{		
		FindMax_L(L, idx, e);// 查找最大的节点位置idx和其值e
		ListInsert(L1, 1, e);// 插入元素e
		ListDelete(L, idx, &e);// 删除节点i
	}
	return 0;
}

void visit(ElemType c) /* ListTraverse()调用的函数(类型要一致) */
{
	printf("%d ",c);
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

void main()
{
	LinkList L, L1;
	InitList(&L);
	CreateList2(&L,5); /* 正位序输入n个元素的值 */
	printf("排序前L="); /* 输出链表La的内容 */
	ListTraverse(L,visit);

	
	ListSort_L(L, L1);	// 排序
	ListTraverse(L1,visit); // 遍历打印排序结果

	DestroyList(&L);
	DestroyList(&L1);	
}