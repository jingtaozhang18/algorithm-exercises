#include<bits/stdc++.h>
using namespace std;
int mem[32];

bool judge(int num){
  // 先将其拆分成单个数字，再进行判断
  int i=0,j;
  while(num) mem[i++]=num%10, num/=10;
  for(j=0,i--;j<i;--i,++j) if(mem[i]!=mem[j]) return false;
  return true;
}

int main(void){
  int num;
  cin>>num;
  num=abs(num);
  if(judge(num)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}