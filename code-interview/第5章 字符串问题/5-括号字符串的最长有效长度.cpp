#include<bits/stdc++.h>
using namespace std;

// 第一次漏掉的情况()(())
int dp[100002];  // 计算每个位置结尾的最长匹配
int main(void){
  string str;
  int ans=0,i,j;
  cin>>str;
  for(i=0;i<str.size();++i){
    if(str[i]==')'){
      j=i-dp[i-1]-1;
      if(j>=0 && str[j]=='(') dp[i]=dp[i-1]+2+(j-1>=0?dp[j-1]:0);
    }
    ans=max(ans, dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}