#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];

int main(void){
  int N,M,K,i,j;
  cin>>N>>M>>K;
  for(i=0;i<N;++i) for(j=0;j<M;++j) scanf("%d", &arr[i][j]);
  int a=0,b=M-1;
  while(a<N&&b>=0&&arr[a][b]!=K){
    if(arr[a][b]>K) b--;
    else a++;
  }
  if(arr[a][b]==K) printf("Yes\n");
  else printf("No\n");
  return 0;
}