#include<bits/stdc++.h>
using namespace std;

int mem[32];

int main(void){
  // 转换成k进制，执行无进位加法
  int n, k, t, i, index;
  int tmp[32];
  scanf("%d%d", &n, &k);
  while(n--){
    scanf("%d", &t);
    // 转换成k进制
    memset(tmp, 0, sizeof tmp);
    index=0;
    while(t) tmp[index++]=t%k, t /= k; 
    // 执行无进位加法
    for(i=0;i<index;++i)
        mem[i]=(mem[i]+tmp[i])%k;
  }
  // 将k进制转换成数字
  t=0;
  for(i=31;i>=0;--i) t*=k, t+=mem[i];
  printf("%d\n", t);
  return 0;
}