#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main(void){
  int i,j,ic,dc,rc; // 插入，删除，替换
  string str_a, str_b;
  cin>>str_a>>str_b>>ic>>dc>>rc;
  int len_a=str_a.size(), len_b=str_b.size();
  for(i=0;i<len_a;++i) dp[i][len_b]=(len_a-i)*dc; // 删掉
  for(i=0;i<len_b;++i) dp[len_a][i]=(len_b-i)*ic; // 插入
  dp[len_a][len_b]=0; // 都为空的时候，代价为0
  for(i=len_a-1;i>=0;--i){
    for(j=len_b-1;j>=0;--j){
      dp[i][j]=dp[i+1][j]+dc;
      dp[i][j]=min(dp[i][j],dp[i][j+1]+ic);
      dp[i][j]=min(dp[i][j],dp[i+1][j+1]+rc*(str_a[i]==str_b[j]?0:1));
      //printf("(%d,%d):%d\n",i,j,dp[i][j]);
    }
  }
  printf("%d\n",dp[0][0]);
  return 0;
}