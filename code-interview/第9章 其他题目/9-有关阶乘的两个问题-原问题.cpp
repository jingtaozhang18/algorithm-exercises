// https://www.nowcoder.com/practice/a54d454f00f84dc3a6eeaec7a7233d51?tpId=101&&tqId=33124&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
// 计算所有5因子的数量
#include<bits/stdc++.h>
using namespace std;

int main(void){
  long long n, ans=0;
  cin>>n;
  while(n){
    ans+=(n/5);
    n/=5;
  }
  cout<<ans<<endl;
  return 0;
}