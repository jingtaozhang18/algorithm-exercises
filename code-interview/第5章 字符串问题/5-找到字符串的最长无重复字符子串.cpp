#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int dp[100000];
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,i,ans=1;
  cin>>n;
  for(i=0;i<n;++i)cin>>arr[i];
  map<int, int> mp; // 记录每个字符最后出现的位置
  dp[0]=1,mp[arr[0]]=0;
  for(i=1;i<n;++i){
    if(mp.find(arr[i])!=mp.end()){
      dp[i]=min(i-mp[arr[i]],dp[i-1]+1);
    }else{
      dp[i]=dp[i-1]+1;
    }
    mp[arr[i]]=i, ans=max(ans, dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}