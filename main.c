#include "sing.h"
#include "double.h"

void text()
{
    slist_node* ln = NULL;
    slist_node* lm = NULL;

    sing_push_back(&ln,2);
    sing_push_back(&ln,4);
    sing_push_back(&ln,6);
    sing_push_back(&ln,8);
 
    sing_push_front(&ln,1);
    sing_push_front(&ln,3);
    sing_push_front(&ln,5);
    sing_push_front(&ln,7);

    sing_push_back(&lm,2);
    sing_push_back(&lm,2);
    sing_push_back(&lm,2);
    sing_push_back(&lm,2);


    sing_pop_back(&ln);

    sing_pop_front(&ln);

    sing_add(&ln,lm);


    sing_print(ln);
    sing_print(lm);
}

void text1()
{
    int i = 1;
    slist_node* ln1 = NULL;
    

    sing_push_back(&ln1,2);
    sing_push_back(&ln1,4);
    sing_push_back(&ln1,2);
    sing_push_back(&ln1,2);
    sing_push_back(&ln1,2);
 
    sing_push_back(&ln1,6);
    sing_push_back(&ln1,8);
    sing_push_back(&ln1,2);
    sing_push_back(&ln1,2);
    sing_push_back(&ln1,2);
 
    sing_push_front(&ln1,1);
    sing_push_front(&ln1,3);
    sing_push_front(&ln1,5);
    sing_push_front(&ln1,7);

    sing_print(ln1);


    slist_node* ln2 = sing_find(ln1,2);
    while (ln2)
    {
        printf("第%d个结点:%p->%d\n",i++,ln2,ln2->data);
        ln2 = sing_find(ln2->next,2);
    }

    ln2 = sing_find(ln1,3);
    if (ln2)
    {
        ln2->data = 30;
    }

    sing_print(ln1);

    ln2 = sing_find(ln1,30);
    sing_push_set(&ln1,ln2,15);


    sing_push_set_after(ln2,15);

    sing_print(ln1);

    sing_delete_data(&ln1,2);
    sing_print(ln1);

    sing_disrepeat(&ln1);

    ln1 = sing_overturn(ln1);
    sing_print(ln1);
    
    sing_turn(&ln1);
    // sing_destory(&ln1);
    sing_print(ln1);
}

void text2()
{
    dlist_node *dl;
    double_init(&dl);
    double_push_back(dl,1);
    double_push_back(dl,2);
    double_push_back(dl,3);
    // double_push_back(dl,4);
    // double_push_back(dl,5);
    // double_push_back(dl,6);
    // double_push_front(dl,100);
    // double_push_front(dl,90);
    // double_push_front(dl,80);
    // double_push_front(dl,70);
    // double_push_front(dl,60);
    // double_push_front(dl,50);

    // double_pop_back(dl);
    // double_pop_back(dl);

    // double_push_back(dl,2);
    // double_push_back(dl,2);
    double_push_back(dl,2);
    double_push_back(dl,2);

    // double_pop_front(dl);
    // double_pop_front(dl);


/*查找数据验证*/
    dlist_node* ln2 = double_find(dl,2);
    dlist_node* tem = ln2;
    int i = 0;
    printf("第%d个结点:%p->%d\n",++i,ln2,ln2->data);
    ln2 = double_find(ln2,2);

    while (ln2 != tem)
    {
        printf("第%d个结点:%p->%d\n",++i,ln2,ln2->data);
        ln2 = double_find(ln2,2);
    }

    ln2 = double_find(dl,3);
    double_push_set(ln2,300);

    double_push_set_after(ln2,300);

    // double_pop_reset_after(ln2);
    // ln2 = double_find(dl,50);
    // double_pop_reset(ln2);

    // double_delete_data(ln2,250);


    double_print(dl);


    dlist_node *dl0 = NULL;
    double_init(&dl0);
    double_push_back(dl0,1);
    double_push_back(dl0,1);
    double_push_back(dl0,1);
    double_push_back(dl0,1);
    double_add(dl,dl0);
    double_print(dl);

}

int main(int argc, char const *argv[])
{
    // text();
    // text1();
    text2();
    system("pause");
    return 0;
}






























