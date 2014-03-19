


Status InitList(SqList *L) /* 算法2.3 */
{ /* 操作结果：构造一个空的顺序线性表 */
	(*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!(*L).elem)
		exit(OVERFLOW); /* 存储分配失败 */
	(*L).length=0; /* 空表长度为0 */
	(*L).listsize=LIST_INIT_SIZE; /* 初始存储容量 */
	return OK;
}
Status ListInsert(SqList *L,int i,ElemType e) /* 算法2.4 */
{
	ElemType *newbase,*q,*p;
	if(i<1||i>(*L).length+1) /* i值不合法 */
		return ERROR;
	if((*L).length>=(*L).listsize) /* 当前存储空间已满,增加分配 */
	{
		newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW); /* 存储分配失败 */
		(*L).elem=newbase; /* 新基址 */
		(*L).listsize+=LISTINCREMENT; /* 增加存储容量 */
	}
	q=(*L).elem+i-1; /* q为插入位置 */
	for(p=(*L).elem+(*L).length-1;p>=q;--p) /* 插入位置及之后的元素右移 */
		*(p+1)=*p;
	*q=e; /* 插入e */
	++(*L).length; /* 表长增1 */
	return OK;
}
void main()
{
	SqList La;
	Status i;
	int j;
	i = InitList(&La);
	for (j = 1; j <= 5; j++) /* 在表La中插入5个元素 */
		ListInsert(&La, j, j);
	ListTraverse(La,print);
}