 /* algo2-5.c ʵ���㷨2.11��2.12�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h"
 #include"bo2-2.c"

 void CreateList(LinkList *L,int n) /* �㷨2.11 */
 { /* ��λ��(���ڱ�ͷ)����n��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա�L */
   int i;
   LinkList p;
   *L=(LinkList)malloc(sizeof(struct LNode));
   (*L)->next=NULL; /* �Ƚ���һ����ͷ���ĵ����� */
   printf("������%d������\n",n);
   for(i=n;i>0;--i)
   {
     p=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
     scanf("%d",&p->data); /* ����Ԫ��ֵ */
     p->next=(*L)->next; /* ���뵽��ͷ */
     (*L)->next=p;
   }
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

 void MergeList(LinkList La,LinkList *Lb,LinkList *Lc)/* �㷨2.12 */
 { /* ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С� */
   /* �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
   LinkList pa=La->next,pb=(*Lb)->next,pc;
   *Lc=pc=La; /* ��La��ͷ�����ΪLc��ͷ��� */
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
   pc->next=pa?pa:pb; /* ����ʣ��� */
   free(*Lb); /* �ͷ�Lb��ͷ��� */
   Lb=NULL;
 }

 void visit(ElemType c) /* ListTraverse()���õĺ���(����Ҫһ��) */
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

	InitList(&LCopy);	// ����������
	q = LCopy;

	while (p)
	{
		node = (LNode *)malloc(sizeof(LNode));	// �����½ڵ�
		node->data = p->data;	// ����������
		q->next = node;			// ���½ڵ����ӵ��µ�����ĩβ

		p = p->next;
		q = q->next;
	}
	q->next = NULL;				// ���һ���ڵ�ָ����Ϊ��

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

	// �������La������
	printf("La="); 
	ListTraverse(La,visit);

	// ͳ��������ĳ��ֵ��Ԫ�ظ���
	ListCount(La, 4, &count);
	printf("count = %d\n", count);


	// ��������
	ListCopy(La, &Lb);

	// �������Lb������
	printf("Lb="); 
	ListTraverse(Lb,visit);

	DestroyList(&La);
	DestroyList(&Lb);

	return;	

 }
