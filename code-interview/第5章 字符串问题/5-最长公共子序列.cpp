#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000];
int main(void){
  string str_a, str_b;
  cin>>str_a>>str_b;
  int len_a=str_a.size(), len_b=str_b.size(),i,j;
  if(!len_a||!len_b) {printf("-1\n"); return 0;}
  // 边界初始化
  for(i=0;i<len_a;++i) if(str_a[i]==str_b[0]||(i>0&&dp[i-1][0])) dp[i][0]=1;
  for(i=1;i<len_b;++i) if(str_a[0]==str_b[i]||dp[0][i-1]) dp[0][i]=1;
  // 递推运算
  for(i=1;i<len_a;++i){
    for(j=1;j<len_b;++j){
      dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
      if(str_a[i]==str_b[j])
        dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
    }
  }
  stack<char>sta;
  i=len_a-1,j=len_b-1;
  while(i&&j){
    if(dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1]){
      sta.push(str_a[i]);
      --i,--j;
    }else if(dp[i][j]==dp[i-1][j]) --i;
    else  --j;
  }
//  cout<<"max: "<<dp[len_a-1][len_b-1]<<endl;
  if(dp[i][j]) sta.push(str_a[i]);
  while(!sta.empty()){
    cout<<sta.top();
    sta.pop();
  }
  cout<<endl;
  return 0;
}