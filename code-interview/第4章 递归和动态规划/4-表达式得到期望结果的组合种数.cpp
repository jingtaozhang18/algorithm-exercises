#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll dp[252][252][2]; // [i][j][0] 块i到块j之间组成0的情况的种类
ll M=1e9+7;
bool validator(const string& str){
  int len=str.size();
  if(len==0||len%2==0) return false;
  for(int i=0;i<len;++i){
    if(i%2==0){ // 偶数
      if(str[i]!='0'&&str[i]!='1') return false;
    }else{ // 奇数
      if(str[i]!='&'&&str[i]!='|'&&str[i]!='^') return false;
    }
  }
  return true;
}
pair<ll, ll> calc(char op, ll lf, ll lt , ll rf, ll rt){ // false true的数量
  
  ll F=0,T=0;
  if(op=='&'){
    T=lt*rt, T%=M;
    F=lt*rf, F%=M;
    F+=lf*rt, F%=M;
    F+=lf*rf, F%=M;
  }else if(op=='|'){
    T=lt*rt, T%=M;
    T+=lt*rf, T%=M;
    T+=lf*rt, T%=M;
    F=lf*rf, F%=M;
  }else{ // 异或
    T=lt*rf, T%=M;
    T+=lf*rt, T%=M;
    F=lt*rt; F%=M;
    F+=lf*rf, F%=M;
  }
  return make_pair(F,T);
}


ll makeDp(const string& str, bool des){
  int len=str.size(),i,j,k,split;
  int block=(len>>1)+1; // 块
  for(k=0;k<block;++k){ // 最大间距block-1
    for(i=0;i<block-k;++i){
      j=i+k;
      if(!k){ // 初始化
        if(str[i<<1]=='0') dp[i][j][0]=1;
        else dp[i][j][1]=1;
      }else{ // 动态规划 
        for(split=i;split<j;++split){
          pair<ll, ll> t=calc(str[(split<<1)+1],dp[i][split][0], dp[i][split][1],dp[split+1][j][0],dp[split+1][j][1]);
          dp[i][j][0]+=t.first, dp[i][j][1]+=t.second;
          dp[i][j][0]%=M, dp[i][j][1]%=M;
        }
      }
//      printf("(%d, %d): %lld\t%lld\n", i,j,dp[i][j][0],dp[i][j][1]);
    }
  }
  return dp[0][block-1][int(des)];
}
int main(void){
  string str,str_des;
  bool des;
  cin>>str>>str_des;
  des = str_des=="true"?true:false;
  if(!validator(str)) {printf("0\n"); return 0;}
  ll ans=makeDp(str, des);
  printf("%lld\n",ans);
  return 0;
}