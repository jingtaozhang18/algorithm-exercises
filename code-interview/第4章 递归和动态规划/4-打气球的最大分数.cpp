#include<bits/stdc++.h>
using namespace std;

int arr[502];
int dp[502][502]; // dp[i][j] 代表[i,j]范围内的最佳结果，且[i-1]和[j+1]气球都在

int main(void){
  int n,i,j,k,t;
  scanf("%d",&n);
  if(n==0) {printf("%d\n",0); return 0;}
  for(i=1;i<=n;++i) scanf("%d",&arr[i]);
  arr[0]=arr[n+1]=1;
  for(i=1;i<=n;++i) dp[i][i]=arr[i-1]*arr[i]*arr[i+1]; // 初始化对角线位置
  for(i=1;i<n;++i){ // dp[j][j+i]
    for(j=1;j+i<=n;++j){
      t=arr[j-1]*arr[j]*arr[j+i+1]+dp[j+1][j+i]; // 最后打掉arr[j]
      t=max(t,arr[j+i+1]*arr[j+i]*arr[j-1]+dp[j][j+i-1]); // 最后打掉arr[j+i]
      for(k=j+1;k<j+i;++k) // 最后打掉arr[k]
        t=max(t,dp[j][k-1]+dp[k+1][j+i]+arr[j-1]*arr[j+i+1]*arr[k]);
      dp[j][j+i]=t;
    }
  }
  printf("%d\n",dp[1][n]);
  return 0;
}