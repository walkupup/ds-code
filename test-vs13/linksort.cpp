
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

// ��L����, �õ�L1
Status ListSort_L(LinkList &L, LinkList &L1)
{
	ElemType e;
	int idx;

	InitList(&L1);
	while (L->next != NULL)
	{		
		FindMax_L(L, idx, e);// �������Ľڵ�λ��idx����ֵe
		ListInsert(L1, 1, e);// ����Ԫ��e
		ListDelete(L, idx, &e);// ɾ���ڵ�i
	}
	return 0;
}

void visit(ElemType c) /* ListTraverse()���õĺ���(����Ҫһ��) */
{
	printf("%d ",c);
}

void CreateList2(LinkList *L,int n)
{ /* ��λ��(���ڱ�β)����n��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա� */
	int i;
	LinkList p,q;
	*L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ��� */
	(*L)->next=NULL;
	q=*L;
	printf("������%d������\n",n);
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
	CreateList2(&L,5); /* ��λ������n��Ԫ�ص�ֵ */
	printf("����ǰL="); /* �������La������ */
	ListTraverse(L,visit);

	
	ListSort_L(L, L1);	// ����
	ListTraverse(L1,visit); // ������ӡ������

	DestroyList(&L);
	DestroyList(&L1);	
}