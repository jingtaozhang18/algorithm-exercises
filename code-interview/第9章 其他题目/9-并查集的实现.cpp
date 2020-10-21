// https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372?tpId=101&&tqId=33134&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

int arr[1000002];
int n;
int find(int v){
  if(v==arr[v]) return v;
  arr[v]=find(arr[v]);
  return arr[v];
}

void isSameSet(int a, int b){
  if(find(a)==find(b)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

void funion(int a, int b){
  if((a=find(a))==(b=find(b))) return;
  arr[a]=b;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int i,opn,op,a,b;
  cin>>n>>opn;
  for(i=1;i<=n;++i) arr[i]=i;
  for(i=0;i<opn;++i){
    cin>>op>>a>>b;
    if(op==1) isSameSet(a,b);
    else funion(a,b);
  }
  return 0;
}