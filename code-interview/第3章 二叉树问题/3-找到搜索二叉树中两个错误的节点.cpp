#include<bits/stdc++.h>
using namespace std;

int tree [500002][2];
void create_tree(int count){
  int f;
  while(count--){
    scanf("%d",&f);
    scanf("%d%d",&tree[f][0],&tree[f][1]);
  }
}
void calc(int root){ // 找到出错节点
  // 中序遍历
  stack<int> sta;
  int pre=-1,a,b;
  bool flag=false;
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
    //cout<<"C:"<<root<<" "<<tree[root][0]<<" "<<tree[root][1]<<endl;
    if(!flag&&pre>root){ // 第一次降序
      a=pre,b=root,flag=true;
    }else if(flag&&pre>root){
      b=root;
    }
    pre=root;
    if(tree[root][1]) root=tree[root][1];
    else root=0;
  }
  printf("%d %d\n",b,a);
}
int main(void){
  int count,root;
  scanf("%d%d",&count,&root);
  create_tree(count);
  calc(root);
}