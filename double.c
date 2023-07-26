#include "double.h"

/*创建一个结点*/
dlist_node* buy_double_node(list_data_type x)
{
    dlist_node* newnode = (dlist_node*)malloc(sizeof(dlist_node));
    if (newnode == NULL)
    {
        printf("buy double link node error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

/*初始化一个循环双链表*/
void double_init(dlist_node **pphead)
{
    dlist_node* newnode = (dlist_node*)malloc(sizeof(dlist_node));
    if (newnode == NULL)
    {
        printf("init double link node error");
        exit(-1);
    }
    newnode->data = NULL;
    newnode->next = newnode;
    newnode->prev = newnode;
    *pphead = newnode;
}

/*打印链表的内容*/
void double_print(dlist_node* phead)
{
    assert(phead);
    dlist_node* tem = phead->next;
    while (tem != phead)
    {
        printf("%d-> ",tem->data);
        tem = tem->next;
    }
    printf("NULL\n");
}

/*在循环双链表尾部插入一个数据*/
void double_push_back(dlist_node* phead,list_data_type x)
{
    assert(phead);
    dlist_node* newnode = buy_double_node(x);
    dlist_node* temp = phead;
    newnode->prev = temp->prev;
    (temp->prev)->next = newnode;
    newnode->next = temp;
    temp->prev = newnode;
}

/*在循环双链表头部插入一个数据*/
void double_push_front(dlist_node* phead,list_data_type x)
{
    assert(phead);
    dlist_node* newnode = buy_double_node(x);
    // dlist_node* temp = phead;
    // newnode->prev = temp;
    // newnode->next = temp->next;
    // temp->next->prev = newnode;
    // temp->next = newnode;
    dlist_node* temp = phead->next;
    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = temp;
    temp->prev = newnode;
}

/*在循环双链表尾部删除一个数据*/
void double_pop_back(dlist_node *phead)
{
    assert(phead);
    assert(phead->next != phead);
    dlist_node *temp = phead->prev;
    phead->prev = temp->prev;
    temp->prev->next = phead;
    free(temp);
    temp = NULL;
}

/*在循环双链表头部删除一个数据*/
void double_pop_front(dlist_node *phead)
{
    assert(phead);
    assert(phead->next != phead);
    dlist_node *temp = phead->next;
    phead->next = temp->next;
    temp->next->prev = phead;
    free(temp);
    temp = NULL;
}

/*查找指定数据在循环双链表中位置的地址*/
dlist_node* double_find(dlist_node* phead,list_data_type x)
{
    dlist_node* temp = phead->next;
    while (temp != phead)
    {
        if (temp->data == x)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

/*在指定数据前面插入一个数据*/
void double_push_set(dlist_node *pos,list_data_type x)
{
    assert(pos);
    dlist_node *newnode = buy_double_node(x);
    dlist_node *temp = pos->prev;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = pos;
    pos->prev = newnode;
}

/*在指定数据后面插入一个数据*/
void double_push_set_after(dlist_node *pos,list_data_type x)
{
    dlist_node *newnode = buy_double_node(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

/*删除指定位置的数据*/
void double_pop_reset(dlist_node *pos) 
{
    assert(pos);
    assert(pos->prev);
    dlist_node *temp = pos->prev;
    temp->next = pos->next;
    pos->next->prev = temp;
    free(pos);
    pos = NULL;
}

/*删除指定位置的后一个数据*/
void double_pop_reset_after(dlist_node *pos) 
{
    assert(pos);
    assert(pos->next);
    dlist_node *prev = pos->next;
    pos->next = prev->next;
    free(prev);
    pos = NULL;
}

/*删除一整个循环双链表*/
void double_destory(dlist_node *phead)
{
    assert(phead);
    dlist_node *temp = phead->next;
    while (temp != phead)
    {
        dlist_node *tem = temp->next;
        free(temp);
        temp = tem;
    }
    phead = NULL;
}

/*删除循环双链表中指定的数据*/
void double_delete_data(dlist_node *phead,list_data_type x)
{
    // assert(phead);
    // assert(phead->next);

    if (phead != NULL)
    {
        assert(phead->next);
        dlist_node *temp = phead->next;
        while (temp != phead)
        {
            if (temp->data == x)
            {
                dlist_node *tem = temp->next;
                double_pop_reset(temp);
                temp = tem;
            }
            else
            {
                temp = temp->next;  
            }
        }
    }
}

/*将第二个循环双链表链接到第一个循环双链表上面*/
void double_add(dlist_node *phead1,dlist_node *phead2)
{
    assert(phead1 && phead2);
    dlist_node *tem1 = phead1->prev;
    dlist_node *tem2 = phead2->next;
    tem1->next = tem2;
    tem2->prev = tem1;
    phead2->prev->next = phead1;
    phead1->prev = phead2->prev;
    free(phead2);
}






















