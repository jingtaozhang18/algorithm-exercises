#include<bits/stdc++.h>
using namespace std;
int mem[1000000];
int dp[1000000];
int main(void){
  int n,i,XOR;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",&mem[i]);
  map<int,int> mp;
  mp[0]=-1;
  dp[0]=mem[0]==0?1:0;
  XOR=mem[0];
  mp[XOR]=0;
  for(i=1;i<n;++i){
    XOR ^= mem[i];
    auto it=mp.find(XOR);
    if(it!=mp.end()){
      dp[i]=it->second==-1?1:dp[it->second]+1;
    }
    mp[XOR]=i;
    dp[i]=max(dp[i],dp[i-1]);
  }
  cout<<dp[n-1]<<endl;
  return 0;
}