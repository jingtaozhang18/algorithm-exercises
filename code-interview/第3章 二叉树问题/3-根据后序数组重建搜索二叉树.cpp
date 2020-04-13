#include<iostream>
using namespace std;

int mem[500002];

bool calc(int L, int R){
  if(L>=R-1) return true;
//  printf("%d (%d, %d)\n",mem[R], L, R);
  int root=mem[R],i,j;
  for(i=L;i<=R&&mem[i]<root;++i);
  for(j=i;j<R;++j) if(mem[j]<root) return false;
  return calc(L,i-1) && calc(i,R-1); // 注意范围控制
}

int main(void){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",&mem[i]);
  if(calc(0,n-1)) printf("true\n");
  else printf("false\n");
  return 0;
}


