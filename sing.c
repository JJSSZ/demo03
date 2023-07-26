#include "sing.h"

/*创建一个结点*/
slist_node* buy_sing_node(list_data_type x)
{
    slist_node* newnode = (slist_node*)malloc(sizeof(slist_node));
    if (newnode == NULL)
    {
        printf("buy sing link node error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

/*打印链表的内容*/
void sing_print(slist_node* phead)
{
    assert(phead);
    while (phead != NULL)
    {
        printf("%d-> ",phead->data);
        phead = phead->next;
    }
    printf("NULL\n");
}

/*在链表尾部插入一个数据*/
void sing_push_back(slist_node** pphead,list_data_type x)
{
    assert(pphead);
    slist_node* newnode = buy_sing_node(x);
    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    else
    {
        slist_node* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

/*在链表头部插入一个数据*/
void sing_push_front(slist_node** pphead,list_data_type x)
{
    assert(pphead);
    slist_node* newnode = buy_sing_node(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

/*在链表尾部删除一个数据*/
void sing_pop_back(slist_node **pphead)
{
    assert(pphead);
    if (*pphead == NULL)
    {
        return ;
    }
    assert(*pphead != NULL);
    if ((*pphead)->next == NULL)
    {
        free(*pphead);
        (*pphead) = NULL;
    }
    else
    {
        slist_node* tail = *pphead;
        while (tail->next->next)
        {
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

/*在链表头部删除一个数据*/
void sing_pop_front(slist_node **pphead)
{
    assert(pphead);
    if (*pphead == NULL)
    {
        return ;
    }
    else if ((*pphead)->next == NULL)
    {
        free(*pphead);
        (*pphead) = NULL;
    }
    else
    { 
        slist_node* temp = (*pphead)->next;
        free((*pphead));
        (*pphead) = temp;
    }
}

/*查找指定数据在链表中位置的地址*/
slist_node* sing_find(slist_node* phead,list_data_type x)
{
    slist_node* p = phead;
    while (p)
    {
        if (p->data == x)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL;
}

/*在指定数据前面插入一个数据*/
void sing_push_set(slist_node **pphead,slist_node *pos,list_data_type x)
{
    assert(pphead);
    slist_node *newnode = buy_sing_node(x);
    if(*pphead == pos)
    {
        newnode->next = *pphead;
        *pphead = newnode;
    }
    else
    {
        slist_node *pos_prev = *pphead;
        while (pos_prev->next != pos)
        {
            pos_prev = pos_prev->next;
        }
        pos_prev->next = newnode;
        newnode->next = pos;
    }
}

/*在指定数据后面插入一个数据*/
void sing_push_set_after(slist_node *pos,list_data_type x)
{
    slist_node *newnode = buy_sing_node(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

/*删除指定数据前面插入一个数据*/
void sing_pop_reset(slist_node **pphead,slist_node *pos) 
{
    assert(pphead);
    if (*pphead == pos)
    {
        sing_pop_front(pphead);
    }
    else
    {
        slist_node *prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
        pos = NULL;
    }  
}

/*删除指定数据后面插入一个数据*/
void sing_pop_reset_after(slist_node *pos) 
{
    assert(pos);
    assert(pos->next == NULL);
    slist_node *prev = pos->next;
    pos->next = prev->next;
    free(prev);
    pos = NULL;
}

/*删除一整个链表*/
void sing_destory(slist_node **pphead)
{
    assert(pphead);
    slist_node *temp = *pphead;
    while (temp)
    {
        slist_node *tem = temp->next;
        free(temp);
        temp = tem;
    }
    *pphead = NULL;
}

/*删除链表中指定的数据*/
void sing_delete_data(slist_node **pphead,list_data_type x)
{
    slist_node *temp = *pphead;
    while (temp)
    {
        if (temp->data == x)
        {
            slist_node *tem = temp->next;
            sing_pop_reset((pphead),temp);
            temp = tem;
        }
        else
        {
            temp = temp->next;  
        }
    }
}

/*去除链表中重复的数据*/
void sing_disrepeat(slist_node **pphead)
{
    if ((*pphead) == NULL)
    {
        return;
    }
    slist_node *temp = *pphead;
    while (temp)
    {
        slist_node *tem = temp->next;
        while (tem)
        {
            if ((tem->data) == (temp->data))
            {
                slist_node *t = tem->next;
                sing_pop_reset(pphead,tem);
                tem = t;
            }
            else
            {
                tem = tem->next; 
            }
        }
        temp = temp->next;
    }
}

/*翻转这个链表,并返回一个链表地址*/
slist_node* sing_overturn(slist_node *phead)
{
    // if (phead == NULL)
    // {
    //     return NULL;
    // }
    // slist_node *n1,*n2,*n3;
    // n1 = NULL;
    // n2 = phead;
    // n3 = phead->next;
    // while (n2)
    // {
    //     n2->next = n1;
    //     n1 = n2;
    //     n2 = n3;
    //     if(n3 != NULL)
    //     {
    //         n3 = n3->next;
    //     }
    // }
    // return n1;

    slist_node *cur = phead;
    slist_node *newhead = NULL;
    while (cur)
    {
        slist_node *temp = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = temp;
    }
    return newhead;
}

/*翻转这个链表*/
void sing_turn(slist_node **pphead)
{
    slist_node *cur = *pphead;
    slist_node *newhead = NULL;
    while (cur)
    {
        slist_node *temp = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = temp;
    }
    *pphead = newhead;
}

/*将第二个链表链接到第一个链表上面*/
void sing_add(slist_node **pphead1,slist_node *phead2)
{
    if (*pphead1 == NULL)
    {
        *pphead1 = phead2;
    }
    else
    {
        slist_node *cur = *pphead1;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = phead2;
    }
}






















