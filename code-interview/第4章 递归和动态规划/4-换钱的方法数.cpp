#include<bits/stdc++.h>
using namespace std;

int arr[1000];
long long dp[1002][20002];
int MOD=1e9+7;
int main(void){
  int n,aim,i,j;
  scanf("%d%d",&n,&aim);
  for(i=0;i<n;++i) scanf("%d",&arr[i]);
  for(i=0;i<=aim;++i) if(i%arr[0]==0) dp[0][i]=1;
  for(i=1;i<n;++i) dp[i][0]=1;
  for(i=1;i<n;++i){
    for(j=1;j<=aim;++j){
      dp[i][j]=dp[i-1][j];
//      printf("%d",dp[i][j]);
      if(j-arr[i]>=0) dp[i][j]+=dp[i][j-arr[i]],dp[i][j]%=MOD;
//      printf("(%d) ",dp[i][j]);
    }
//    printf("\n");
  }
  printf("%lld\n",dp[n-1][aim]);
  return 0;
}