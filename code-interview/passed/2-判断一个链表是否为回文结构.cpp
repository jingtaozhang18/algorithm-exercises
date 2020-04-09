# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

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


 void check(list_node * head)
{
    //////在下面完成代码
  int count=0,i;
  list_node *pc=head;
  while(pc) count++, pc=pc->next;
  stack<int> sta;
  pc=head;
  for(i=1;i<=(count>>1);++i){
    sta.push(pc->val);
    pc=pc->next;
  }
  if(count%2==1) pc=pc->next;
  while(pc){
    if(sta.empty() || pc->val!=sta.top()) {
      cout<<"false"<<endl;
      return;
    } 
    sta.pop();
    pc=pc->next;
  }
  if(sta.empty()){
    cout<<"true"<<endl;
  }
  else {
    cout<<"false"<<endl;
  }
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}