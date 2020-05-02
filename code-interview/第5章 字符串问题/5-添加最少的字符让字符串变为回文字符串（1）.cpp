#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000]; // dp[i][j] str[i:j] 变成回文需要添加的最少字符数

void makeDP(string& str){ // 计算DP矩阵
  int diff,i,j,len=str.size();
  for(diff=1;diff<len;++diff){
    for(i=0;i<len-diff;++i){
      j=i+diff;
      if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1];
      else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
    }
  }
}
int main(void){
  string str;
  cin>>str;
  makeDP(str);
  int i=0,j=str.size()-1,left=0;
  while(dp[i][j]){ // 不为0就是需要修改
    if(dp[i][j-1]+1==dp[i][j]){ // 左侧小，补左侧
      str.insert(i+left,1,str[j+left]);
      left++,j--;
    }else if(dp[i+1][j]+1==dp[i][j]){ // 补右侧
      str.insert(j+1+left,1,str[i+left]);
      i++;
    }else i++,j--;
  }
  cout<<str<<endl;
  return 0;
}