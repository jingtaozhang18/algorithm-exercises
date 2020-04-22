#include<bits/stdc++.h>
using namespace std;

int main(void){
  int ans=0x80000001,n,t,cur=0;
  scanf("%d", &n);
  while(n--){
    scanf("%d",&t);
    cur=max(cur+t, t);
    ans=max(ans,cur);
  }
  printf("%d\n", ans);
  return 0;
}