#include<bits/stdc++.h>
using namespace std;

int M=1e9+7;
int dp[100000];
int main(void){
  string str;
  cin>>str;
  int len=str.size(),i,p,c;
  for(i=0;i<len;++i){
    if(i==0) {
      if(str[i]-'0'>0) dp[i]=1;
      else {
        printf("0\n"); //无法组成
        return 0;
      }
    }
    else {
      p=str[i-1]-'0', c=str[i]-'0';
      if(!p&&!c){ // 无法组成
        printf("0\n");
        return 0;
      }
      if(c) dp[i]=dp[i-1]; // 自成一词
      if(p&&10*p+c<=26){ // 和前面的拼接
        if(i==1) dp[i]++;
        else dp[i]+=dp[i-2];
      }
      dp[i]%=M;
    }
  }
  printf("%d\n",dp[len-1]);
  return 0;
}