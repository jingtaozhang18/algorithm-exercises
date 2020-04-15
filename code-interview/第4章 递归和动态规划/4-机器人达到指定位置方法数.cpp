#include<bits/stdc++.h>
using namespace std;

long long dp[5002][5002];
int MOD=1e9+7;

int main(void){
  int N,M,K,P,i,j;// 地图，原使位置，步数，目标位置
  scanf("%d%d%d%d",&N,&M,&K,&P);
  dp[0][M]=1;
  for(i=1;i<=K;++i){
//    for(j=1;j<=N;++j) dp[i][j]=dp[i-1][j]; // 原来的位置不能继续待
    for(j=1;j<=N;++j){
      if(dp[i-1][j]){ // 可以从此位置出发
        if(j==1) dp[i][j+1]+=dp[i-1][j],dp[i][j+1]%=MOD;
        else if(j==N) dp[i][j-1]+=dp[i-1][j],dp[i][j-1]%=MOD;
        else dp[i][j+1]+=dp[i-1][j],dp[i][j-1]+=dp[i-1][j],dp[i][j-1]%=MOD,dp[i][j+1]%=MOD;
      }
    }
  }
  printf("%lld\n",dp[K][P]);
  return 0;
}