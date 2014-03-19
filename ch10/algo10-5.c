 /* algo10-5.c �����㷨10.6(a)�ĳ��� */
 #include<stdio.h>
 typedef int InfoType; /* ������������������� */
 #include"c10-1.h"
 int Partition(SqList *L,int low,int high)
 { /* ����˳���L���ӱ�L.r[low..high]�ļ�¼��ʹ�����¼��λ�� */
   /* ������������λ�ã���ʱ����֮ǰ(��)�ļ�¼������(С)�������㷨10.6(a) */
   RedType t;
   KeyType pivotkey;
   pivotkey=(*L).r[low].key; /* ���ӱ��ĵ�һ����¼�������¼ */
   while(low<high)
   { /* �ӱ������˽�������м�ɨ�� */
     while(low<high&&(*L).r[high].key>=pivotkey)
       --high;
     t=(*L).r[low]; /* ���������¼С�ļ�¼�������Ͷ� */
     (*L).r[low]=(*L).r[high];
     (*L).r[high]=t;
     while(low<high&&(*L).r[low].key<=pivotkey)
       ++low;
     t=(*L).r[low]; /* ���������¼��ļ�¼�������߶� */
     (*L).r[low]=(*L).r[high];
     (*L).r[high]=t;
   }
   return low; /* ������������λ�� */
 }

 #include"bo10-2.c"
 #define N 8
 void main()
 {
   RedType d[N]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
   SqList l;
   int i;
   for(i=0;i<N;i++)
     l.r[i+1]=d[i];
   l.length=N;
   printf("����ǰ:\n");
   print(l);
   QuickSort(&l);
   printf("�����:\n");
   print(l);
 }