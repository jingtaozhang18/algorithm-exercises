#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n, t, ans=0;
  scanf("%d",&n);
  while(n--){
    scanf("%d", &t);
    ans^=t;
  }
  printf("%d\n", ans);
  return 0;
}