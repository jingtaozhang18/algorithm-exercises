#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000];
int main(void){
  string str;
  cin>>str;
  int i,j,k,l,len=str.size();
  for(k=1;k<len;++k){
    for(i=0;i<len-k;++i){
      j=i+k;
      dp[i][j]=(str[i]==str[j])?dp[i+1][j-1]:dp[i+1][j-1]+2;
      for(l=i+1;l<j;++l) // 好无奈
        dp[i][j]=min(dp[i][j],dp[i][l-1]+dp[l][j]+1);
    //   printf("[%d, %d]: %d\n",i,j,dp[i][j]);
    }
    // printf("\n");
  }
  cout<<dp[0][len-1]<<endl;
  return 0;
}