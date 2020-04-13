#include<bits/stdc++.h>
using namespace std;
int tree[500002][2];
bool isSearch(int root){
  stack<int>sta;
  int pre=-1;
  while(!sta.empty()||root){
    if(!root){
      root=sta.top();
      sta.pop();
    }else{
      while(tree[root][0]){
        sta.push(root);
        root=tree[root][0];
      }
    }
    if(pre>root) return false; // 中序遍历
    pre=root;
    if(tree[root][1]) root=tree[root][1];
    else root=0;
  }
  return true;
}
bool isComplete(int root){
  queue<int> que;
  que.push(root);
  bool last=false; // 一旦开始没有节点，就不能再有节点
  while(!que.empty()){
    root=que.front();
    que.pop();
    if(tree[root][0]){
      if(last) return false;
      que.push(tree[root][0]);
    }else{
      last=true;
    }
    if(tree[root][1]){
      if(last) return false;
      que.push(tree[root][1]);
    }else{
      last=true;
    }
  }
  return true;
}
int main(void){
  int n,root,i,a,b,c;
  scanf("%d%d",&n,&root);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    scanf("%d%d",&tree[a][0],&tree[a][1]);
  }
  if(isSearch(root)) printf("true\n");
  else printf("false\n");
  if(isComplete(root)) printf("true\n");
  else printf("false\n");
  return 0;
}