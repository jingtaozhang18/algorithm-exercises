// https://www.nowcoder.com/practice/418d2fcdf7f24d6f8f4202e23951c0da?tpId=101&&tqId=33119&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

priority_queue<long long> que;

int main(){
  long long n,i,v,a,b,ans=0;
  cin>>n;
  for(i=0;i<n;++i){
    cin>>v;
    que.push(-v);
  }
  while(que.size()>1){
    a=que.top();que.pop();b=que.top();que.pop();
    ans+=(a+b);que.push(a+b);
  }
  cout<<-ans<<endl;
  return 0;
}