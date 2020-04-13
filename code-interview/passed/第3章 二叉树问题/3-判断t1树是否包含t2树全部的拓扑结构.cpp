#include<bits/stdc++.h>
using namespace std;

int ta [2002][2];
int tb [2002][2];
void create_tree(int ma[2002][2], int count){
  int f;
  while(count--){
    scanf("%d",&f);
    scanf("%d%d",&ma[f][0],&ma[f][1]);
  }
}
bool sub(int ra, int rb){
  // 找子结构
  if(!rb) return true;
  if(!ra&&rb)return false;
  return sub(ta[ra][0],tb[rb][0]) && sub(ta[ra][1],tb[rb][1]);
}
void calc(int root, int rb){ // 找拓扑结构包含
  // 中序遍历
  stack<int> sta;
  while(!sta.empty()||root){
    if(!root){
      root=sta.top();
      sta.pop();
    }else{
      while(ta[root][0]){
        sta.push(root);
        root=ta[root][0];
      }
    }
    if(sub(root,rb)){
      printf("true\n");
      return;
    }
    if(ta[root][1]) root=ta[root][1];
    else root=0;
  }
  printf("false\n");
  return;
}
int main(void){
  int ca,ra;
  scanf("%d%d",&ca,&ra);
  create_tree(ta, ca);
  int cb,rb;
  scanf("%d%d",&cb,&rb);
  create_tree(tb, cb);
  calc(ra, rb);
}