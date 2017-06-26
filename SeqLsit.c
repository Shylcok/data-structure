/************************
 *顺序表操作的实现        *
 *2017/06/26 15：00 PM  *
 *Shylock               *
 ************************/


/*①初始化 ListInitiate(L)*/
void ListInitiate(SeqList *L)//初始化顺序表L
{
    L->size = 0;             //定义初始数据元素个数
}
/*②求当前元素个数 ListLength(L)*/
void ListLength(SeqList L)   //
{
    return L.size;
}
/*③插入数据元素 ListInsert(L,i,x)*/
int ListInsert(SeqList *L,int i,DataType x)
//在顺序表的第i（0<=i<=size）个位置前插入数据元素值
//插入成功返回1，插入失败返回0
{
    int j;
    if(L->size>=Maxsize)
    {
        printf("顺序表已满无法插入！")
        return 0;
    }
else if(i<0||i>L->size)
    {
        printf("参数不合法！\n");
        return 0;
    }
    else
    {
        //从后往前依次后移数据，为插入做准备
        for(j = L->size;j > i; j--)L->list[j]=L->[j-1];
        L->list[i] = x;       //插入x
        L->size ++;           //元素个数+1
        return 1;
    }
}
/*④删除数据元素 ListDelete(L,i,x)*/
int ListDelete(SeqList *L, int i, DataType *x)
//删除顺序表L中第i(0<=i<=size-1)个位置处的数据元素并保存到x中
//删除成功返回1，删除失败返回0
{
    int j;
    if(L->size<=0)
    {
        printf("顺序表已空无数据元素可删！");
        return 0;
    }
    else if(i<0||i>L.size-1)
    {
        printf("参数i不合法！");
        return 0;
    }
    else
    {
        *x=L->list[i];        //保存尚处的元素到x中
        //从前向后依次前移
        for(j=i+1;j<=L->size-1;j++)L->size[j-1]=L->list[j];
        L->size--;            //数据元素个数-1
        return 1;
    }
}
/*⑤取数据元素 ListGet(L,i,x)*/
int ListGet(SeqList *L,int i,DataType *x)
//取顺序表L中第i个数据元素存于x中，成功返回1，失败返回0
{
    if(i<0||i>L.size-1)
    {
        printf("参数i不合法！");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return1
    }
}


