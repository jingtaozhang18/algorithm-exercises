#include<bits/stdc++.h>
using namespace std;

long long mem[10002];
const long M = 1e9 + 7;
int main(){
  int n,i,j;
  scanf("%d",&n);
  if(n<2){
    printf("2\n");
    return 0;
  }else{
    mem[0]=mem[1]=1;
    for(i=2;i<=n;++i){ // 动态规划
      for(j=0;j<i;++j){
        mem[i]+=mem[j]*mem[i-1-j];
        mem[i]=mem[i]%M;
      }
    }
    printf("%d\n",mem[n]);
  }
}