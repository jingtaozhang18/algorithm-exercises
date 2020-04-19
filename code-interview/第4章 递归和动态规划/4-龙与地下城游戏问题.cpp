#include<bits/stdc++.h>
using namespace std;

int mem[1000][1000];
int dp[1000][1000]; // dp[i,j] 从[i,j]位置到最终位置需要的最少血量
int main(void){
  int n,m,i,j;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i)for(j=0;j<m;++j)scanf("%d",&mem[i][j]);
  // 找出到达每个位置的最佳情况
  for(i=n-1;i>=0;--i){
    for(j=m-1;j>=0;--j){
      if(i==n-1&&j==m-1){
        dp[i][j]=max(1-mem[i][j], 1);
      }else if(i==n-1){
        dp[i][j]=max(dp[i][j+1]-mem[i][j], 1);
      }else if(j==m-1){
        dp[i][j]=max(dp[i+1][j]-mem[i][j], 1);
      }else{
        dp[i][j]=max(dp[i][j+1]-mem[i][j], 1);
        dp[i][j]=min(dp[i][j],max(dp[i+1][j]-mem[i][j], 1));
      }
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}