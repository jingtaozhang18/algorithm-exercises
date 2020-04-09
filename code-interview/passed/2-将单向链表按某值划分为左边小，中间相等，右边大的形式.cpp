# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

int pivot;

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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


void list_partition(list_node * head, int pivot)
{
    //////在下面完成代码
  list_node *ps,*psg,*pe,*peg,*pl,*plg,*pc=head,*phead=nullptr,*ptail=nullptr;
  ps=new list_node();ps->next=NULL;
  pe=new list_node();pe->next=NULL;
  pl=new list_node();pl->next=NULL;
  psg=ps,peg=pe,plg=pl;
  while(pc){
    if(pc->val<pivot) psg->next=pc,psg=psg->next;
    else if(pc->val==pivot) peg->next=pc,peg=peg->next;
    else plg->next=pc,plg=plg->next;
    pc=pc->next;
  }
  // 清理末端
  psg->next=peg->next=plg->next=nullptr;
  // 拼接
  if(ps->next){
    phead=ps->next;
    ptail=psg;
  } 
  if(pe->next){
    if(!phead) phead=pe->next;
    else ptail->next=pe->next;
    ptail=peg;
  }
  if(pl->next){
    if(!phead) phead=pl->next;
    else ptail->next=pl->next;
    ptail=plg;
  } 
  while(phead){
    printf("%d ",phead->val);
    phead=phead->next;
  }
  printf("\n");
}


int main ()
{
    list_node * head = input_list();
    list_partition(head, pivot);
    return 0;
}