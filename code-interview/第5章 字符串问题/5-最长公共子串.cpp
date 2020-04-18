#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000];
int main(void){
  string str_a,str_b;
  cin>>str_a>>str_b;
  int len_a=str_a.size(),len_b=str_b.size(),i,j;
  if(!len_a||!len_b){cout<<-1<<endl; return 0;}
  int ans_i=0, ans_j=0;
  for(i=0;i<len_a;++i){
    for(j=0;j<len_b;++j){
      if(str_a[i]==str_b[j])
        if(i&&j) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=1;
      else
        dp[i][j]=0;
      if(dp[i][j]>dp[ans_i][ans_j]) ans_i=i,ans_j=j;
    }
  }
  // ans_i, ans_j 最大位置
//  cout<<"max: "<<dp[ans_i][ans_j]<<endl;
  if(!dp[ans_i][ans_j]){cout<<-1<<endl; return 0;}
  cout<<str_b.substr(ans_j-dp[ans_i][ans_j]+1,dp[ans_i][ans_j])<<endl;
  return 0;
}