 /* bo2-9.c ���������Ա�(�洢�ṹ��c2-2.h����)����չ����(11��) */
 void InsertAscend(LinkList L,ElemType e)
 { /* ��ʼ���������ǽ������е����Ա�L�Ѵ��ڡ������������L�а��ǽ�������µ�����Ԫ��e */
   LinkList q=L,p=L->next;
   while(p&&e>p->data)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); /* ����q�� */
   q->next->data=e;
   q->next->next=p;
 }

 void InsertDescend(LinkList L,ElemType e)
 { /* ��ʼ�����������������е����Ա�L�Ѵ��ڡ������������L�а�����������µ�����Ԫ��e */
   LinkList q=L,p=L->next;
   while(p&&e<p->data)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); /* ����q�� */
   q->next->data=e;
   q->next->next=p;
 }

 Status HeadInsert(LinkList L,ElemType e)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L��ͷ�������µ�����Ԫ��e,��Ϊ�����ĵ�һ��Ԫ�� */
   LinkList s;
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ����㸳ֵ */
   s->next=L->next; /* ���ڱ�ͷ */
   L->next=s;
   return OK;
 }

 Status EndInsert(LinkList L,ElemType e)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L��β�������µ�����Ԫ��e,��Ϊ���������һ��Ԫ�� */
   LinkList p=L;
   while(p->next) /* ʹpָ���βԪ�� */
     p=p->next;
   p->next=(LinkList)malloc(sizeof(struct LNode)); /* �ڱ�β�����½�� */
   p->next->data=e; /* ���½�㸳ֵ */
   p->next->next=NULL; /* ��β */
   return OK;
 }

 Status DeleteFirst(LinkList L,ElemType *e)
 { /* ��ʼ���������Ա�L�Ѵ��ڣ����в�����1��Ԫ�� */
   /* ���������ɾ��L�ĵ�һ������Ԫ�أ�����e������ֵ */
   LinkList p=L->next;
   if(p)
   {
     *e=p->data;
     L->next=p->next;
     free(p);
     return OK;
   }
   else
     return ERROR;
 }

 Status DeleteTail(LinkList L,ElemType *e)
 { /* ��ʼ���������Ա�L�Ѵ��ڣ����в�����1��Ԫ�� */
   /* ���������ɾ��L�����һ������Ԫ�أ�����e������ֵ */
   LinkList p=L,q;
   if(!p->next) /* ����Ϊ�� */
     return ERROR;
   while(p->next)
   {
     q=p;
     p=p->next;
   }
   q->next=NULL; /* ��β����next����ΪNULL */
   *e=p->data;
   free(p);
   return OK;
 }

 Status DeleteElem(LinkList L,ElemType e)
 { /* ɾ������ֵΪe��Ԫ�أ�������TRUE�����޴�Ԫ�أ��򷵻�FALSE */
   LinkList p=L,q;
   while(p)
   {
     q=p->next;
     if(q&&q->data==e)
     {
       p->next=q->next;
       free(q);
       return TRUE;
     }
     p=q;
   }
   return FALSE;
 }

 Status ReplaceElem(LinkList L,int i,ElemType e)
 { /* ��eȡ����L�е�i��Ԫ�ص�ֵ */
   LinkList p=L;
   int j=0;
   while(p->next&&j<i)
   {
     j++;
     p=p->next;
   }
   if(j==i)
   {
     p->data=e;
     return OK;
   }
   else /* ���в����ڵ�i��Ԫ�� */
     return ERROR;
 }

 Status CreatAscend(LinkList *L,int n)
 { /* ���ǽ�����n��Ԫ�ص����Ա� */
   int j;
   LinkList p,q,s;
   if(n<=0)
     return ERROR;
   InitList(L);
   printf("������%d��Ԫ��:\n",n);
   s=(LinkList)malloc(sizeof(struct LNode)); /* ��һ����� */
   scanf("%d",&s->data);
   s->next=NULL;
   (*L)->next=s;
   for(j=1;j<n;j++)
   {
     s=(LinkList)malloc(sizeof(struct LNode)); /* ������ */
     scanf("%d",&s->data);
     q=*L;
     p=(*L)->next;
     while(p&&p->data<s->data) /* pû����β������ָԪ��ֵС����ֵ */
     {
       q=p;
       p=p->next; /* ָ����� */
     }
     s->next=q->next; /* Ԫ�ز���q�ĺ��� */
     q->next=s;
   }
   return OK;
 }

 Status CreatDescend(LinkList *L,int n)
 { /* ����������n��Ԫ�ص����Ա� */
   int j;
   LinkList p,q,s;
   if(n<=0)
     return ERROR;
   InitList(L);
   printf("������%d��Ԫ��:\n",n);
   s=(LinkList)malloc(sizeof(struct LNode)); /* ��һ����� */
   scanf("%d",&s->data);
   s->next=NULL;
   (*L)->next=s;
   for(j=1;j<n;j++)
   {
     s=(LinkList)malloc(sizeof(struct LNode)); /* ������ */
     scanf("%d",&s->data);
     q=*L;
     p=(*L)->next;
     while(p&&p->data>s->data) /* pû����β������ָԪ��ֵ������ֵ */
     {
       q=p;
       p=p->next; /* ָ����� */
     }
     s->next=q->next; /* Ԫ�ز���q�ĺ��� */
     q->next=s;
   }
   return OK;
 }

 Status GetFirstElem(LinkList L,ElemType *e)
 { /* ���ر�ͷԪ�ص�ֵ */
   LinkList p=L->next;
   if(!p) /* �ձ� */
     return ERROR;
   else /* �ǿձ� */
     *e=p->data;
   return OK;
 }