#include<bits/stdc++.h>
using namespace std;

int tree[500002][3];
void sub(int target){
  while(tree[target][0])target=tree[target][0];
  printf("%d\n",target);
}

int main(void){
  int n,root,i,a,b,c,target;
  scanf("%d%d",&n,&root);
  for(i=0;i<n;++i){
    scanf("%d%d%d",&a,&b,&c);
    tree[a][0]=b,tree[a][1]=c,tree[b][2]=a,tree[c][2]=a;
  }
  tree[root][2]=0;
  scanf("%d",&target);
  if(tree[target][1]){ // 右孩子存在
    target=tree[target][1];
    sub(target);
  }else{ //向上找
    while(target){
      if(tree[tree[target][2]][0]==target) {
        printf("%d\n",tree[target][2]); // 是左孩子
        return 0;
      } else{ // 是右孩子
        target=tree[target][2];
      }
    }
    printf("0\n");
  }
  return 0;
}