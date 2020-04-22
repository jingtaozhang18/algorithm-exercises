#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a,ans=0;
  scanf("%d",&a);
  while(a){
    ans++;
    a = (a-1) & a;
  }
  printf("%d\n", ans);
  return 0;
}