#include<bits/stdc++.h>
using namespace std;

bool arr[5000][5000]; // 记录str[i,j]是否是回文
int dp[5000]; // 记录str[i,:]需要切分的次数
int main(void){
  string str;
  cin>>str;
  int i,j,k,l,len=str.size();
  // 生成arr数组
  for(k=0;k<len;++k){
    for(i=0;i<len-k;++i){
      j=i+k;
      if(k==0) arr[i][j]=true;
      else if(k==1){
        if(str[i]==str[j]) arr[i][j]=true;
      }else{
        if(str[i]==str[j]&&arr[i+1][j-1]) arr[i][j]=true;
      }
    }
  }
  for(i=len-1;i>=0;--i){
    dp[i]=INT_MAX;
    for(j=i;j<len;++j){
      if(arr[i][j]) dp[i]=min(dp[i],j+1==len?0:dp[j+1]+1);
    }
    // cout<<i<<"\t"<<dp[i]<<endl;
  }
  cout<<dp[0]<<endl;
  return 0;
}