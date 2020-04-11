# include<bits/stdc++.h>
using namespace std;
// 直接输出，存起来的方式会超时
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
void preOrderNoRecur(node* root){
  stack<node*> sta;
  while(!sta.empty() || root){
    if(!root){
      root=sta.top();
      sta.pop();
    }else{
      printf("%d!",root->val);
      while(root->lch){
        sta.push(root);
        root=root->lch;
        printf("%d!",root->val);
      }
      printf("#!");
    }
    if(root->rch) root=root->rch;
    else{
      printf("#!");
      root=nullptr;
    }
  }
}
void levelOrder(node* root){
  queue<node*> que;
  que.push(root);
  while(!que.empty()){
    root=que.front();
    que.pop();
    if(root){
      printf("%d!",root->val);
      que.push(root->lch);
      que.push(root->rch);
    }else{
      printf("#!");
    }
  }
}

int main(void){
  int n,val;
  cin>>n>>val;
  node* root=create_tree(n, val);
  preOrderNoRecur(root); printf("\n");
  levelOrder(root); printf("\n");
  return 0;
}