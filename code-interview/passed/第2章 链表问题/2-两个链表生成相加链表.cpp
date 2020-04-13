# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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
list_node * reverse_list(list_node *head){
  // 反转链表,保证head一定存在
  list_node *pr=nullptr,*pc=head,*pn=head->next;
  while(pc){
    pc->next=pr;
    pr=pc,pc=pn;
    if(pn) pn=pn->next;
  }
  return pr;
}


list_node * add_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
  list_node*h1=reverse_list(head1);
  list_node*h2=reverse_list(head2);
  list_node*ans=new list_node();
  int a,b,c=0,t;
  while(h1||h2||c){
    a=b=0;
    if(h1) a=h1->val, h1=h1->next;
    if(h2) b=h2->val, h2=h2->next;
    t=a+b+c;
    ans->val=t%10,c=t/10;
    list_node*lt=new list_node();
    lt->next=ans,ans=lt;
  }
  return ans->next;
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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}