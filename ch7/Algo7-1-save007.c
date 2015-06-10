 /* algo7-1.c �����㷨7.7��7.8 */
 #include"c1.h"
 #define MAX_NAME 2 /* �����ַ�������󳤶�+1 */
 typedef char ElemType[MAX_NAME];
 typedef ElemType TElemType;
 #include"c6-5.h"
 typedef int InfoType;
typedef char VertexType[MAX_NAME];
#include<windows.h>

#include"c7-2.h"
 #include"bo7-2.c"

 void DFSTree(ALGraph G,int v,CSTree *T)
 { /* �ӵ�v���������������ȱ���ͼG,������TΪ�������������㷨7.8 */
   Boolean first=TRUE;
   int w;
   CSTree p,q;
   VertexType v1,w1;
   visited[v]=TRUE;
   strcpy(v1,*GetVex(G,v));
   for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,strcpy(w1,*GetVex(G,w)))) /* w����Ϊv���ڽӶ��� */
     if(!visited[w]) /* w���㲻�������� */
     {
       p=(CSTree)malloc(sizeof(CSNode)); /* ���亢�ӽ�� */
       strcpy(p->data,*GetVex(G,w));
       p->firstchild=NULL;
       p->nextsibling=NULL;
       if(first)
       { /* w��v�ĵ�һ��δ�����ʵ��ڽӶ��� */
         (*T)->firstchild=p;
         first=FALSE; /* �Ǹ��ĵ�һ�����ӽ�� */
       }
       else /* w��v������δ�����ʵ��ڽӶ��� */
	 q->nextsibling=p; /* ����һ�ڽӶ�����ֵܽ��ý�� */
       q=p;
       DFSTree(G,w,&q); /* �ӵ�w���������������ȱ���ͼG,������������q */
     }
 }

 void DFSForest(ALGraph G,CSTree *T)
 { /* ��������ͼG�������������ɭ�ֵ�(����)����(��)�ֵ�����T���㷨7.7 */
   CSTree p,q;
   int v;
   *T=NULL;
   for(v=0;v<G.vexnum;++v)
     visited[v]=FALSE; /* ����ֵ */
   for(v=0;v<G.vexnum;++v) /* �ӵ�0���������� */
     if(!visited[v])
     { /* ��v����Ϊ�µ��������ĸ���� */
       p=(CSTree)malloc(sizeof(CSNode)); /* �������� */
       strcpy(p->data,*GetVex(G,v));
       p->firstchild=NULL;
       p->nextsibling=NULL;
       if(!*T) /* �ǵ�һ���������ĸ�(T�ĸ�) */
         *T=p;
       else /* �������������ĸ�(ǰһ�õĸ��ģ��ֵܣ�) */
         q->nextsibling=p;
       q=p; /* qָʾ��ǰ�������ĸ� */
       DFSTree(G,v,&p); /* ������pΪ���������� */
     }
 }

 void PreOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { /* �ȸ��������ӣ��ֵܶ�������ṹ����T(bo6-5.c��) */
   if(T)
   {
     Visit(T->data); /* �ȷ��ʸ���� */
     PreOrderTraverse(T->firstchild,Visit); /* ���ȸ������������� */
     PreOrderTraverse(T->nextsibling,Visit); /* ����ȸ�������һ���ֵ����� */
   }
 }

 void print(char *i)
 {
   printf("%s ",i);
 }



#define LAKE_WIDTH_007 100
#define JUMP_DIST_007 10

 int Jump(ALGraph G, int v, int w)
 {
	 int pt1[2];
	 int pt2[2];

	 pt1[0] = G.vertices[v].x[0];
	 pt1[1] = G.vertices[v].x[1];
	 pt2[0] = G.vertices[w].x[0];
	 pt2[1] = G.vertices[w].x[1];

	 if ((pt1[0] - pt2[0]) * (pt1[0] - pt2[0]) + (pt1[1] - pt2[1]) * (pt1[1] - pt2[1]) < 
		 JUMP_DIST_007 * JUMP_DIST_007)
		 return 1;
	 else
		 return 0;
 }

 int IsSafe(ALGraph G, int v)
 {
	 if (G.vertices[v].x[0] < -LAKE_WIDTH_007 / 2 + JUMP_DIST_007 ||
		 G.vertices[v].x[0] > LAKE_WIDTH_007 / 2 - JUMP_DIST_007)
		 return 1;
	 if (G.vertices[v].x[1] < -LAKE_WIDTH_007 / 2 + JUMP_DIST_007 ||
		 G.vertices[v].x[1] > LAKE_WIDTH_007 / 2 - JUMP_DIST_007)
		 return 1;
	  
	 return 0;
 }
 int DFS007(ALGraph G, int v)
 {
	 int w;
	 int answer = 0;
	 VertexType v1, w1;
	 visited[v] = TRUE; 
	 if (IsSafe(G, v))
		 answer = 1;
	 else
	 {
		 for (w = 0; w < G.vexnum; w++)
		 {
			 if (!visited[w] && w != v && Jump(G, v, w))
				 answer = DFS007(G, w);
			 if (answer == 1)
				 break;
		 }
	 }
 }
 void save007(ALGraph G)
 {
	 int v;
	 int answer = 0;
	 
	 for (v = 0; v < G.vexnum; v++)
		 visited[v] = FALSE; /* ���ʱ�־�����ʼ�� */
	 for (v = 0; v < G.vexnum; v++)
	 {
		 if (!visited[v] && Jump(G, 0, v))
			 answer = DFS007(G, v); /* ����δ���ʵĶ������DFS */
		 if (answer == 1)
			 break;
	 }

	 if (answer == 1)
		 printf("yes\n");
	 else
		 printf("no\n");
	 return;
 }

 void main()
 {
   ALGraph g;
   int num = 100;
   int i;
   srand(GetTickCount());

   g.vertices[0].x[0] = 0;
   g.vertices[0].x[1] = 0;

   for (i = 1; i < num + 1; i++)
   {
	   g.vertices[i].x[0] = (rand() % LAKE_WIDTH_007) - LAKE_WIDTH_007 / 2;
	   g.vertices[i].x[1] = (rand() % LAKE_WIDTH_007) - LAKE_WIDTH_007 / 2;
   }
   g.vexnum = num + 1;
   
   save007(g);

   //CSTree t;
   //printf("��ѡ������ͼ\n");
   //CreateGraph(&g);
   //Display(g);
   //DFSTraverse(g, print);

   //DFSForest(g,&t);
   //printf("�ȸ���������ɭ�֣�\n");
   //PreOrderTraverse(t,print);
   printf("\n");
 }
