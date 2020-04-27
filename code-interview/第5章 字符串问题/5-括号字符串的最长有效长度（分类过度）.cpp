#include<bits/stdc++.h>
using namespace std;

// 第一次漏掉的情况()(())
int dp[100002];  // 计算每个位置结尾的最长匹配
int main(void){
  string str;
  int ans=0,i,j;
  cin>>str;
  for(i=0;i<str.size();++i){
    if(str[i]!=')') dp[i]=0;
    else{
      j=i-1;
      if(j>=0&&str[j]=='(') { //  匹配到刚前面的左括号，()()
        dp[i]=2;
        j--;
        if(j>=0) dp[i]+=dp[j];
      }
      else if(j>=0){ // 前面是右括号 (())
        j=j-dp[j];
        if(j>=0&&str[j]=='(') {
          dp[i]=dp[i-1]+2;
          j--; // ()(())
          if(j>=0) dp[i]+=dp[j];
        }
      }
    }
//    cout<<"i:"<<i<<" val:"<<dp[i]<<endl;
    ans=max(ans, dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}