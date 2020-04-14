#include<bits/stdc++.h>
using namespace std;

int tree[1002][2];
map<int,map<int, int> > mp;

void initRecord(int root){
  if(!root) return;
  mp[root]=map<int,int>();
  initRecord(tree[root][0]);
  initRecord(tree[root][1]);
}

void headRecord(int child, int root){
  if(!child) return;
  mp[child][root]=root;
  headRecord(tree[child][0],root);
  headRecord(tree[child][1],root);
}
void preRight(int l, int r, int h){
  if(!r) return;
  mp[l][r]=h;
  preRight(l,tree[r][0],h);
  preRight(l,tree[r][1],h);
}

void preLeft(int l, int r, int h){
  if(!l) return;
  preRight(l,r,h);
  preLeft(tree[l][0],r,h);
  preLeft(tree[l][1],r,h);
}

void subRecord(int root){ // 记录左右子之间的组合
  if(!root) return;
  preLeft(tree[root][0],tree[root][1],root);
//  subRecord(tree[root][0]);
//  subRecord(tree[root][1]);
}

void build(int root){
  if(!root) return;
  headRecord(tree[root][0],root);
  headRecord(tree[root][1],root);
  subRecord(root);
  build(tree[root][0]);
  build(tree[root][1]);
}

int main(void){
  int n,root,i,a,b,c;
  scanf("%d%d",&n,&root);
  for(i=0;i<n;++i){
    scanf("%d%d%d",&a,&b,&c);
    tree[a][0]=b,tree[a][1]=c;
  }
  build(root);
  scanf("%d",&n);
  for(i=0;i<n;++i){
    scanf("%d%d",&a,&b);
    if(a==b) c=a;
    else if(mp[a].find(b)!=mp[a].end()) c=mp[a][b];
    else if(mp[b].find(a)!=mp[b].end()) c=mp[b][a];
    printf("%d\n",c);
  }
  return 0;
}