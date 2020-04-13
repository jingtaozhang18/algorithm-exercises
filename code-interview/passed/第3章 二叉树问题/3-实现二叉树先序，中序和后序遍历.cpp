# include<bits/stdc++.h>
using namespace std;
// 参考书中观点，更简洁
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
void preOrder(node* root){
  if(root) {
    cout<<root->val<<" ";
    preOrder(root->lch);
    preOrder(root->rch);
  }
}
void inOrder(node* root){
  if(root){
    inOrder(root->lch);
    cout<<root->val<<" ";
    inOrder(root->rch);
  }
}
void posOrder(node* root){
  if(root){
    posOrder(root->lch);
    posOrder(root->rch);
    cout<<root->val<<" ";
  }
}
void preOrderNoRecur(node* root){
  stack<node*> sta;
  while(!sta.empty() || root){
    if(!root){
      root=sta.top();
      sta.pop();
    }else{
      cout<<root->val<<" ";
      while(root->lch){
        sta.push(root);
        root=root->lch;
        cout<<root->val<<" "; // 一移动就打印
      }
    }
    if(root->rch) root=root->rch;
    else root=nullptr;
  }
}
void inOrderNoRecur(node* root){
  stack<node*> sta;
  while(!sta.empty() || root){
    if(!root){
      root=sta.top();
      sta.pop();
    }
    else{
      while(root->lch){
        sta.push(root);
        root=root->lch;
      }
    }
    cout<<root->val<<" ";
    if(root->rch) root=root->rch;
    else root=nullptr;
  }
}
void posOrderNoRecur(node* root){
  stack<node*> sta;
  stack<node*> aux; // 辅助栈
  while(!sta.empty() || root){
    if(!root){ 
      root=sta.top();
      sta.pop();
    }else{
      while(root->lch){
        sta.push(root);
        root=root->lch;
      }
    }
    if(root->rch) {
      aux.push(root); // 右孩子存在，所以需要压栈
      root=root->rch;
    }
    else {
      // 末端节点
      cout<<root->val<<" ";
      while(!aux.empty() && (aux.top()->rch==root||aux.top()->rch==nullptr)){ // 父节点的右孩子是当前节点
        root=aux.top();
        cout<<root->val<<" ";
        aux.pop();
      }
      root=nullptr;
    }
  }
}

int main(void){
  int n,val;
  cin>>n>>val;
  node* root=create_tree(n, val);
  preOrderNoRecur(root); cout<<endl;
  inOrderNoRecur(root); cout<<endl;
  posOrderNoRecur(root); cout<<endl;
  return 0;
}