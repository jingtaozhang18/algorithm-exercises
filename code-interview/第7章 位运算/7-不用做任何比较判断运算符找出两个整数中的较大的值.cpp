#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a,b;
  scanf("%d%d",&a,&b);
  int t=0x80000000;
  int sa=a&t; // 0代表是0或者正数
  int sb=b&t;
  if(sa&&!sb) {printf("%d\n",b); return 0;}
  if(!sa&&sb) {printf("%d\n",a); return 0;}
  int d=a-b;
  int sd=d&t;
  if(sd) {printf("%d\n",b);}
  else {printf("%d\n",a);}
  return 0;
}