/************************
 *单链表操作的实现        *
 *2017/06/26 15：37 PM  *
 *Shylock               *
 ************************/


/*Ⅰ.初始化 ListInitiate(SLNode **head)*/
void ListInitiate(SLNode **head)             //初始化
{
    *head = (SLNode *)malloc(sizeof(SLNode));//申请头结点，由head指示其地址
    (*head)->next =Null;                     //置结束标志NULL       
}
/*Ⅱ.求当前数据元素个数 ListLength(SLNode *head)*/
int ListLength(SLNode *head)
{
    SLNode *p = head;                        //p指向头结点
    int size = 0;                            //size初始为0

    while(p->next!=NULL)                     //循环计数
    {
        p = p->next;
        size ++;
    }
    return size;
}
/*Ⅲ.插入 ListInsert(SLNode *head,int i,DataType x)*/
int ListInsert(SLNode *head,int i,DataType x)
//在带头结点的单链表head的第i(0<=i<=size)个节点前插入一个存放数据元素x的结点
//插入成功返回1，失败则返回0
{
    SLNode *p,*q;
    int j;

    p = head;
    j = -1;
    while(p->next!=NULL&&j<i-1)
    //最终让指针p指向i-1个结点
    {
        p = p->next;
        j++;
    }

    if(j!=i-1)
    {
        printf("插入元素位置参数错！");
        return 0;
    }

    q = (SLNode *)malloc(sizeof(SLNode));  //生成新结点
    q->data =x;                            //新结点数据域赋值

    q->next = p->next;                     //插入步骤1
    p->next =q;                            //插入步骤2
    return 1;
}
/*删除 ListDelete(SLNode *head,int i,DataType *x)*/
int ListDelete(SLNode *head,int i,DataType *x)
//删除带头结点单链表head的第i(0<=i<=size-1)个结点
//被删除结点的数据域值由x带回，删除成功返回1，删除失败则返回0
{
    SLNode *p,*s;
    int j;
    p = head;
    j = -1;
    while(p->next!=NULL&&p->next!=NULL&&j<i-1)
    //循环结束时指针p指向第i-1个结点
    {
        p=p->next;
        j++;
    }

    if(j!=i-1)
    {
        printf("删除元素位置参数错误！");
        return 0;
    }

    s = p->next;                            //指针s指向a(i)结点
    *x = s->data;                           //把指针指向的结点的数据域值赋予x
    p->next = p->next->next;                //删除
    free(s);                                //释放指针s所指结点的内存空间
    return 1;
}
/*Ⅴ取数据元素 ListGet(SLNode *head,int i,DataType *x)*/
int ListGet(SLNode *head,int i,DataType *x)
{
    SLNode *p;
    int j;
    p = head;
    j = -1;
    while(p->next !=NULL&&j<i)
    {
        p = p->next; j++;
    }

    if(j!=i)
    {
        printf("取元素位置参数端！");
        return 0;
    }

    *x = p->data;
    return 1;
}
/*Ⅵ撤销单链表 Destroy(SLNode **head)*/
void Destory(SLNode **head)
{
    SLNode *p,*p1;

    p = head;
    while(p!=NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}





