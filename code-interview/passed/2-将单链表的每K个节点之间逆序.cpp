# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
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
bool need_reverse(list_node*head,int K){
  // 判断是否需要反转
  while(K--){
    if(head)head=head->next;
    else return false;
  }
  return true;
}

list_node * reverse_knode(list_node * head, int K)
{
  //////在下面完成代码
  list_node*pf=nullptr,*ph,*ans=nullptr,*pr=nullptr,*pc=head,*pn=head->next;
  while(need_reverse(pc,K)){
    ph=pc;
    for(int i=0;i<K;++i){
      pc->next=pr;
      pr=pc,pc=pn;
      if(pn) pn=pn->next;
    }
    if(!ans) ans=pr;
    if(pf) pf->next=pr;
    ph->next=pc,pf=ph;
  }
  if(!ans) return head;
  else return ans;
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
    int K;
    scanf("%d", &K);
    list_node * new_head = reverse_knode(head, K);
    print_list(new_head);
    return 0;
}