#include<bits/stdc++.h>
using namespace std;

bool dp[5001][5001]; // [i,j] 表示 str_a[i:]和str_b[j:]可以组成aim[i+j:]
int main(void){
  int i,j;
  string str_a,str_b,aim;
  cin>>str_a>>str_b>>aim;
  int len_a=str_a.size(), len_b=str_b.size(), len_aim=aim.size();
  if(len_a+len_b!=len_aim) {cout<<"NO"<<endl; return 0;}
  dp[len_a][len_b]=false;
  for(i=len_a;i>=0;--i){
    for(j=len_b;j>=0;--j){
      if(i==len_a&&j==len_b) {
        dp[i][j]=true; // 给出希望
      }else if(i==len_a){
        dp[i][j]=(aim[i+j]==str_b[j] && dp[i][j+1]);
      }else if(j==len_b){
        dp[i][j]=(aim[i+j]==str_a[i] && dp[i+1][j]);
      }else{
        dp[i][j]= (aim[i+j]==str_a[i] && dp[i+1][j]) || (aim[i+j]==str_b[j] && dp[i][j+1]);
      }
    }
  }
  if(dp[0][0]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}