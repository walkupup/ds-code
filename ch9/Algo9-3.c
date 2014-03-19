 /* algo9-3.c ��̬���ұ�(��̬����)�Ĳ��� */
 #include"c1.h"
 #define N 9 /* ����Ԫ�ظ��� */
 typedef char KeyType; /* ��ؼ�����Ϊ�ַ��� */
 typedef struct /* ����Ԫ������ */
 {
   KeyType key;
   int weight;
 }ElemType;
 ElemType r[N]={{'A',1},{'B',1},{'C',2},{'D',5},{'E',3},
                {'F',4},{'G',4},{'H',3},{'I',5}}; /* ����Ԫ��(�Խ̿�����9-1Ϊ��),ȫ�ֱ��� */
 int sw[N+1]; /* �ۼ�Ȩֵ��ȫ�ֱ��� */
 #include"c9.h"
 #include"c9-1.h"
 #include"bo9-1.c"

 typedef ElemType TElemType;
 #include"c6-2.h"
 Status SecondOptimal(BiTree *T, ElemType R[],int sw[],int low,int high)
 { /* �������R[low..high]�����ۼ�Ȩֵ��sw(����sw[0]==0)�ݹ鹹�� */
   /* ���Ų�����T���㷨9.3 */
   int i,j;
   double min,dw;
   i=low;
   min=fabs(sw[high]-sw[low]);
   dw=sw[high]+sw[low-1];
   for(j=low+1;j<=high;++j) /* ѡ����С�ġ�Piֵ */
     if(fabs(dw-sw[j]-sw[j-1])<min)
     {
       i=j;
       min=fabs(dw-sw[j]-sw[j-1]);
     }
   *T=(BiTree)malloc(sizeof(BiTNode));
   if(!*T)
     return ERROR;
   (*T)->data=R[i]; /* ���ɽ�� */
   if(i==low)
     (*T)->lchild=NULL; /* �������� */
   else
     SecondOptimal(&(*T)->lchild,R,sw,low,i-1); /* ���������� */
   if(i==high)
     (*T)->rchild=NULL; /* �������� */
   else
     SecondOptimal(&(*T)->rchild,R,sw,i+1,high); /* ���������� */
   return OK;
 }

 void FindSW(int sw[],SSTable ST)
 { /* ���������ST�и�����Ԫ�ص�Weight�����ۼ�Ȩֵ��sw */
   int i;
   sw[0]=0;
   for(i=1;i<=ST.length;i++)
     sw[i]=sw[i-1]+ST.elem[i].weight;
 }

 typedef BiTree SOSTree; /* ���Ų��������ö��������Ĵ洢�ṹ */
 Status CreateSOSTree(SOSTree *T,SSTable ST)
 { /* �������ST����һ�ô��Ų�����T��ST������Ԫ�غ���Ȩ��weight���㷨9.4 */
   if(ST.length==0)
     *T=NULL;
   else
   {
     FindSW(sw,ST); /* ���������ST�и�����Ԫ�ص�Weight�����ۼ�Ȩֵ��sw */
     SecondOptimal(T,ST.elem,sw,1,ST.length);
   }
   return OK;
 }

 Status Search_SOSTree(SOSTree *T,KeyType key)
 { /* �ڴ��Ų�����T�в��ҹؼ��ֵ���key��Ԫ�ء��ҵ��򷵻�OK�����򷵻�FALSE */
   while(*T) /* T�ǿ� */
     if((*T)->data.key==key)
       return OK;
     else if((*T)->data.key>key)
       *T=(*T)->lchild;
     else
       *T=(*T)->rchild;
   return FALSE; /* ˳����в����ڴ���Ԫ�� */
 }

 void print(ElemType c) /* Traverse()���õĺ��� */
 {
   printf("(%c %d) ",c.key,c.weight);
 }

 void main()
 {
   SSTable st;
   SOSTree t;
   Status i;
   KeyType s;
   Creat_Ord(&st,N); /* ��ȫ����������ǽ���̬���ұ�st */
   Traverse(st,print);
   CreateSOSTree(&t,st); /* �����������һ�ô��Ų����� */
   printf("\n����������ҵ��ַ�: ");
   scanf("%c",&s);
   i=Search_SOSTree(&t,s);
   if(i)
     printf("%c��Ȩֵ��%d\n",s,t->data.weight);
   else
     printf("���в����ڴ��ַ�\n");
 }
