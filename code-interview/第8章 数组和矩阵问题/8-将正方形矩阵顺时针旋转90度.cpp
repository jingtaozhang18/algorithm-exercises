#include<bits/stdc++.h>
using namespace std;

int m[200][200];
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,i,j,t;
  cin>>n;
  for(i=0;i<n;++i)for(j=0;j<n;++j)cin>>m[i][j];
  for(i=0;i<(n<<1);++i){
    for(j=0;j<n-i*2-1;++j){
      t=m[i][j+i]; 
      m[i][j+i]=m[n-1-i-j][i];
      m[n-1-i-j][i]=m[n-1-i][n-i-1-j];
      m[n-1-i][n-i-1-j]=m[i+j][n-i-1];
      m[i+j][n-i-1]=t;
    }
  }
  for(i=0;i<n;++i) {for(j=0;j<n;++j) cout<<m[i][j]<<" "; cout<<endl;}
  return 0;
}