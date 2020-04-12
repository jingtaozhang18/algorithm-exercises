# include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  struct node *lch, *rch;
  node(int val):val(val),lch(nullptr),rch(nullptr){};
};

node* create_tree(int count, int val){
  node* root=new node(val), *t;
  map<int, node*> mp;
  mp[val]=root;
  int vf, vl, vr;
  while(count--){
    scanf("%d%d%d",&vf,&vl,&vr);
    if(vf && mp.find(vf)==mp.end()) mp[vf]=new node(vf);
    if(vl && mp.find(vl)==mp.end()) mp[vl]=new node(vl);
    if(vr && mp.find(vr)==mp.end()) mp[vr]=new node(vr);
    if(vl) mp[vf]->lch=mp[vl];
    if(vr) mp[vf]->rch=mp[vr];
  }
  return root;
}
void zigZagPrint(node*root){
  int level=1,cur=1,next=0;
  bool pos=true;
  deque<node*>que;
  que.push_back(root);
  printf("Level 1 from left to right:");
  while(!que.empty()){
    root=pos?que.front():que.back();
    if(pos) que.pop_front();
    else que.pop_back();
    cur--;
    printf(" %d",root->val);
    if(pos){
      if(root->lch) {
        que.push_back(root->lch);
        next++;
      }
      if(root->rch){
        que.push_back(root->rch);
        next++;
      }
    }else{
      if(root->rch){
        que.push_front(root->rch);
        next++;
      }
      if(root->lch) {
        que.push_front(root->lch);
        next++;
      }
    }
    if(cur==0){
      level++;
      if(next) 
        if(!pos)
          printf("\nLevel %d from left to right:",level);
        else
          printf("\nLevel %d from right to left:",level);
      pos=!pos,cur=next,next=0;
    }
  }
  printf("\n");
}
void levelPrint(node*root){
  int level=1,cur=1,next=0;
  queue<node*>que;
  que.push(root);
  printf("Level 1 :");
  while(!que.empty()){
    root=que.front();
    que.pop();cur--;
    printf(" %d",root->val);
    if(root->lch) {
      que.push(root->lch);
      next++;
    }
    if(root->rch){
      que.push(root->rch);
      next++;
    }
    if(cur==0){
      level++;
      if(next) printf("\nLevel %d :",level);
      cur=next,next=0;
    }
  }
  printf("\n");
}
int main(void){
  int n,val;
  cin>>n>>val;
  node* root=create_tree(n,val);
  levelPrint(root);
  zigZagPrint(root);
  return 0;
}


