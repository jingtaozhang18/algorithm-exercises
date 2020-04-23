#include<bits/stdc++.h>
using namespace std;

int arr[5000];
int dp[2][5000][5000]; 
// dp [0][:][:] 先拿, [1][:][:] 后拿
// dp [][i][j] 在[i,j]的牌面下，能拿到的最高分数

int main(void){
  int n,i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",&arr[i]);
  for(k=0;k<n;++k){ // k代表行列间距
    for(i=0;i<n-k;++i){ 
      j=i+k;
      if(i==j) dp[0][i][j]=arr[i]; // 初始化
      else{ // 动态规划
        dp[0][i][j]=max(dp[1][i+1][j]+arr[i], dp[1][i][j-1]+arr[j]);
        dp[1][i][j]=min(dp[0][i+1][j], dp[0][i][j-1]); // 后拿被动喝汤
      }
    }
  }
  printf("%d\n",max(dp[0][0][n-1], dp[1][0][n-1]));
  return 0;
}