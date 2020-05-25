#include<bits/stdc++.h>
using namespace std;

bool arr[1000][1000];
int len[1000000]; // i*m+j 到起点的长度
int n,m;
bool ok(int i, int j){
  if(i<0||i>=n) return false;
  if(j<0||j>=m) return false;
  return arr[i][j];
}
void deal(int i, int j, int l, queue<int>& que){
  if(!ok(i,j)) return;
  int p=i*m+j;
  len[p]=l+1, arr[i][j]=false;
  que.push(p);
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int i,j,p;
  cin>>n>>m;
  string s;
  for(i=0;i<n;++i){
    cin>>s;
    for(j=0;j<m;++j) arr[i][j]=(s[j]=='1');
  }
  // bfs 搜索
  queue<int> que;
  que.push(0);
  arr[0][0]=false;
  len[0]=1;
  while(!que.empty()){
    p=que.front(); que.pop();
    i=p/m, j=p%m;
    deal(i-1,j,len[p],que); 
    deal(i+1,j,len[p],que);
    deal(i,j-1,len[p],que);
    deal(i,j+1,len[p],que);
  }
  int ans=len[(n-1)*m+(m-1)];
  if (ans) cout<<ans<<endl;
  else cout<<-1<<endl;
  return 0;
}