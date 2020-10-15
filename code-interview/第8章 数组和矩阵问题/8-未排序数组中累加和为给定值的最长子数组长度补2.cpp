// https://www.nowcoder.com/practice/ab190c44af0141d58037c3f95109d722?tpId=101&&tqId=33079&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

int dp[100002];
map<int, int>mp; // 倒排记录
int main(void){
  int n,i,c=0,v,ans=0;
  cin>>n;
  mp[0]=-1;
  for(i=0;i<n;++i){
    cin>>v;
    if(v)c++; else c--;
    dp[i]=c;
    if(mp.find(c)==mp.end()) mp[c]=i;
    if(mp.find(c)!=mp.end()) ans=max(ans, i-mp[c]);
  }
  cout<<ans<<endl;
  return 0;
}