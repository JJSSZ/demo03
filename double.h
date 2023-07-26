#ifndef __DOUBLE_H_
#define __DOUBLE_H_

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "windows.h"

typedef int list_data_type ;

typedef struct list_double
{
    list_data_type data;
    struct list_double* next;
    struct list_double* prev;
}dlist_node;


void double_push_back(dlist_node* phead,list_data_type x);          //在链表尾部插入一个数据
void double_push_front(dlist_node *phead,list_data_type x);         //在链表头部插入一个数据
void double_pop_back(dlist_node *phead);                            //在链表尾部删除一个数据
void double_pop_front(dlist_node *phead);                           //在链表头部删除一个数据
void double_print(dlist_node *phead);                               //打印链表的内容
void double_destory(dlist_node *phead);                             //释放链表内存
void double_push_set(dlist_node *pos,list_data_type x);             //在指链表的定位置前面插入一个数据
void double_push_set_after(dlist_node *pos,list_data_type x);       //在指链表的定位置后面插入一个数据
void double_pop_reset(dlist_node *pos);                             //删除链表指定位置的数据
void double_pop_reset_after(dlist_node *pos);                       //删除链表指定位置的后一个数据
void double_delete_data(dlist_node *phead,list_data_type x);        //删除链表中所有的x
void double_add(dlist_node *phead1,dlist_node *phead2);             //将第二个链表链接到第一个链表上面
void double_init(dlist_node **pphead);

dlist_node* double_find(dlist_node *phead,list_data_type x);         //查找链表中数据x第一次出现的位置



#endif