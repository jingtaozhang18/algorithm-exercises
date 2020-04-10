# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};
void print_list(list_node * head);

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node * selection_sort(list_node * head)
{
    //////在下面完成代码
  // 每次选择链表中最小的节点
  list_node* hp=new list_node();
  list_node* pc=new list_node();
  pc->next=head;
  list_node*max_node=hp,*t; // 最小节点，//遍历开始的位置
  while(pc->next){
    max_node=t=pc;
    while(t->next){
      if(t->next->val > max_node->next->val) {
        max_node=t; // 最大节点的父节点
      }
      t=t->next;
    }
    t=max_node->next;
    max_node->next=t->next;
    t->next=hp->next;
    hp->next=t;
  }
  return hp->next;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head = input_list();
    list_node * new_head = selection_sort(head);
    print_list(new_head);
    return 0;
}