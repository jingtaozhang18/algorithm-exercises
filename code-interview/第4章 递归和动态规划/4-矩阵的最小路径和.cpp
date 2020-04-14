#include<bits/stdc++.h>
using namespace std;

int mem[2002][2002];
int main(void){
  int n,m,i,j;
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&mem[i][j]);
  for(i=2;i<=m;++i)mem[1][i]+=mem[1][i-1];
  for(i=2;i<=n;++i)mem[i][1]+=mem[i-1][1];
  for(i=2;i<=n;++i)
    for(j=2;j<=m;++j)
      mem[i][j]+=min(mem[i-1][j],mem[i][j-1]);
  printf("%d\n",mem[n][m]);
  return 0;
}