#include<bits/stdc++.h>
using namespace std;

int tree[500002][3];
int dfs(int root, int t1, int t2, int&ans){
  if(!root) return 0;
  int count=0;
  if(root==t1||root==t2) count+=1;
  count+=dfs(tree[root][0],t1,t2,ans);
  count+=dfs(tree[root][1],t1,t2,ans);
  if(!ans&&count==2) ans=root;
  return count;
}

int main(void){
  int n,root,i,a,b,c,target;
  scanf("%d%d",&n,&root);
  for(i=0;i<n;++i){
    scanf("%d%d%d",&a,&b,&c);
    tree[a][0]=b,tree[a][1]=c,tree[b][2]=a,tree[c][2]=a;
  }
  scanf("%d%d",&a,&b);
  int ans=0;
  dfs(root,a,b,ans);
  printf("%d\n",ans);
  return 0;
}