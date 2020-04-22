#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a,b;
  scanf("%d%d",&a,&b);
  a ^= b; // 异或是找出两个对象之间的不同之处
  b ^= a;
  a ^= b;
  printf("%d %d\n",a,b);
  return 0;
}