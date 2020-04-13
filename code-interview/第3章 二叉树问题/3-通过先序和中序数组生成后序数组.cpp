#include<bits/stdc++.h>
using namespace std;

int pre[10002];
int in[10002];
int tree[10002][2];

int build(int L, int R, int in_L, int in_R){ // 返回这部分的根节点
  if(L==R) return pre[L];
  int root=pre[L],i;
  for(i=in_L;in[i]!=root;++i);
  if(i-in_L) tree[root][0]=build(L+1,L+i-in_L,in_L,i-1);
  if(in_R-i) tree[root][1]=build(L+i-in_L+1,R,i+1,in_R);
  return root;
};

void posPrint(int root){
  stack<int> sta;
  stack<int> aux;
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
    if(tree[root][1]){
      aux.push(root);
      root=tree[root][1];
    }else{
      printf("%d ", root);
      while(!aux.empty()&& (tree[aux.top()][1]==root||tree[aux.top()][1]==0)){ // 右孩子找到了父亲，或者没有右孩子的时候打印
        root=aux.top();
        printf("%d ", root);
        aux.pop();
      }
      root=0;
    }
  }
}

int main(void){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&pre[i]);
  for(i=0;i<n;i++) scanf("%d",&in[i]);
  int root=build(0,n-1,0,n-1);
  posPrint(root);
  return 0;
}