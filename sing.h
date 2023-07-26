#ifndef __SING_H_
#define __SING_H_

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "windows.h"


typedef int list_data_type ;

typedef struct list_sing
{
    list_data_type data;
    struct list_sing* next;
}slist_node;


void sing_push_back(slist_node** pphead,list_data_type x);               //在链表尾部插入一个数据
void sing_push_front(slist_node **phead,list_data_type x);               //在链表头部插入一个数据
void sing_pop_back(slist_node **pphead);                                 //在链表尾部删除一个数据
void sing_pop_front(slist_node **pphead);                                //在链表头部删除一个数据
void sing_print(slist_node *phead);                                      //打印链表的内容
void sing_destory(slist_node **phead);                                   //释放链表内存
void sing_push_set(slist_node **pphead,slist_node *pos,list_data_type x); //在指链表的定位置前面插入一个数据
void sing_push_set_after(slist_node *pos,list_data_type x);              //在指链表的定位置后面插入一个数据
void sing_pop_reset(slist_node **pphead,slist_node *pos);                 //删除链表指定位置的数据
void sing_delete_data(slist_node **pphead,list_data_type x);             //删除链表中所有的x
void sing_disrepeat(slist_node **pphead);                                //去除链表中重复的值
void sing_turn(slist_node **pphead);                                     //翻转链表
void sing_add(slist_node **pphead1,slist_node *phead2);                   //将第二个链表链接到第一个链表上面

slist_node* sing_find(slist_node *phead,list_data_type x);                //查找链表中数据x第一次出现的位置
slist_node* sing_overturn(slist_node *phead);


#endif