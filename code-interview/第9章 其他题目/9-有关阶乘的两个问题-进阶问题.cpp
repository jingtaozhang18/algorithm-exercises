// https://www.nowcoder.com/practice/29f6e99322044050ae7c37756581c0c1?tpId=101&&tqId=33125&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
// 计算所有2因子的数量
#include<bits/stdc++.h>
using namespace std;

int main(void){
  long long n, ans=0;
  cin>>n;
  while(n){
    ans+=(n/2);
    n/=2;
  }
  cout<<ans<<endl;
  return 0;
}