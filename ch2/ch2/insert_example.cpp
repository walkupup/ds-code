


Status InitList(SqList *L) /* �㷨2.3 */
{ /* �������������һ���յ�˳�����Ա� */
	(*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!(*L).elem)
		exit(OVERFLOW); /* �洢����ʧ�� */
	(*L).length=0; /* �ձ���Ϊ0 */
	(*L).listsize=LIST_INIT_SIZE; /* ��ʼ�洢���� */
	return OK;
}
Status ListInsert(SqList *L,int i,ElemType e) /* �㷨2.4 */
{
	ElemType *newbase,*q,*p;
	if(i<1||i>(*L).length+1) /* iֵ���Ϸ� */
		return ERROR;
	if((*L).length>=(*L).listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
	{
		newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW); /* �洢����ʧ�� */
		(*L).elem=newbase; /* �»�ַ */
		(*L).listsize+=LISTINCREMENT; /* ���Ӵ洢���� */
	}
	q=(*L).elem+i-1; /* qΪ����λ�� */
	for(p=(*L).elem+(*L).length-1;p>=q;--p) /* ����λ�ü�֮���Ԫ������ */
		*(p+1)=*p;
	*q=e; /* ����e */
	++(*L).length; /* ����1 */
	return OK;
}
void main()
{
	SqList La;
	Status i;
	int j;
	i = InitList(&La);
	for (j = 1; j <= 5; j++) /* �ڱ�La�в���5��Ԫ�� */
		ListInsert(&La, j, j);
	ListTraverse(La,print);
}