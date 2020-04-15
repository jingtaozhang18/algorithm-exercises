#include<bits/stdc++.h>
using namespace std;

int mem[1000];
int dp[1000][5002];
 
void calc(int n, int aim){
  for(int i=0; i<n; ++i){
    for(int j=1;j<=aim;++j){
      if(i==0){ // 第一行
        if(j%mem[i]==0) dp[i][j]=j/mem[i];
        else dp[i][j]=-1;
      }else{ // 其它行
        // 下面的代码仍然可以简化
        // int ans=-1,val,t;
        //   for(t=0;t*mem[i]<=j;++t){ // t是本层负担的张数，j-t*mem[i]是之前层负担的
        //     if(dp[i-1][j-t*mem[i]]!=-1){
        //       val=dp[i-1][j-t*mem[i]]+t;
        //       ans=ans==-1?val:min(val,ans);
        //     }
        //   }
        // dp[i][j]=ans;
        // 全由之前的层负担或者当前层和之前的层共同负担
        dp[i][j]=dp[i-1][j];
        if(j-mem[i]>=0 && dp[i][j-mem[i]]!=-1){ // 从当前层的情况进行计算
          if(dp[i][j]==-1) dp[i][j]=dp[i][j-mem[i]]+1;
          else dp[i][j]=min(dp[i][j],dp[i][j-mem[i]]+1);
        }
      }
    }
  }
};
int main(void){
  int n,aim,i;
  scanf("%d%d",&n,&aim);
  for(i=0;i<n;++i)scanf("%d",&mem[i]);
  calc(n, aim);
  printf("%d\n",dp[n-1][aim]);
  return 0;
}