#include<bits/stdc++.h>
using namespace std;
int tree[500002][2];

int process(int root, int& ans){ // 和找公共祖先一个道理
  if(!root) return 0;
  int C=0,L=0,R=0;
  L=process(tree[root][0],ans);
  R=process(tree[root][1],ans);
  ans=max(ans,L+R+1);
  return max(L,R)+1;
}

int main(void){
  int n,root,i,a,b,c;
  scanf("%d%d",&n,&root);
  for(i=0;i<n;++i){
    scanf("%d%d%d",&a,&b,&c);
    tree[a][0]=b,tree[a][1]=c;
  }
  int ans=0;
  process(root,ans);
  printf("%d\n",ans);
  return 0;
}