// https://www.nowcoder.com/practice/e0e3459723e04a64900a2ec53bdf8852?tpId=101&&tqId=33128&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

void calc(int level, int n, bool l){ // 左0右1
  if(level==n) {cout<<(l==0?"down":"up")<<endl;return;}
  calc(level+1,n,0);
  cout<<(l==0?"down":"up")<<endl;
  calc(level+1,n,1);
}

int main(void){
  int n;
  cin>>n;
  calc(1,n,0);
  return 0;
}