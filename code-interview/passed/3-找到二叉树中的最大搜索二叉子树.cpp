# include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  struct node *lch, *rch;
  node(int val):val(val),lch(nullptr),rch(nullptr){};
};
struct status{
  struct node* head; // 最大搜索二叉树的根节点
  int minVal,maxVal; // 最大搜索二叉树的左右边界
  int maxLen;        // 最大搜索二叉树的最大值
  status():head(nullptr),maxLen(0),minVal(1000002),maxVal(-1){};
  status(node* head,int minVal,int maxVal,int maxLen):head(head),minVal(minVal),maxVal(maxVal),maxLen(maxLen){};
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
status calc(node* root){
  status sl;
  status sr; // head节点为空,maxLen为0
  if(root->lch) sl=calc(root->lch);
  if(root->rch) sr=calc(root->rch);
  if((sl.head==root->lch&&sl.maxVal<root->val)
     && (sr.head==root->rch&&sr.minVal>root->val)) // 拼接起来最大,叶子节点也会进入
    return status(root,min(sl.minVal,root->val),max(sr.maxVal,root->val),sl.maxLen+sr.maxLen+1);
  else{
    if(!sl.head) return sr;
    if(!sr.head) return sl;
    if(sl.maxLen<sr.maxLen) return sr;
    else return sl;
  }
};
int main(void){
  int n,val;
  cin>>n>>val;
  node* root=create_tree(n,val);
  status ans=calc(root);
  cout<<ans.maxLen<<endl;
  return 0;
}

