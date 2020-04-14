#include<bits/stdc++.h>
using namespace std;

vector<int> tree[500002]; //树结构
int mem[500002]; // 快乐值

pair<int,int> process(int root){ // <int,int> 当前节点 <来，不来>
  int yes=mem[root];
  int no=0;
  for(int i:tree[root]){
    pair<int,int> p=process(i);
    yes+=p.second;
    no+=max(p.first,p.second);
  }
//  printf("%d,<%d,%d>\n",root,yes,no);
  return make_pair(yes,no);
}
int main(void){
  int n,root,i,a,b,c;
  scanf("%d%d",&n,&root);
  for(i=1;i<=n;++i){
    scanf("%d",&a);
    mem[i]=a;
  }
  for(i=0;i<n-1;++i){ // 注意读取次数
    scanf("%d%d",&a,&b);
    tree[a].push_back(b);
  }
  pair<int,int> p=process(root);
  printf("%d\n",max(p.first,p.second));
  return 0;
}