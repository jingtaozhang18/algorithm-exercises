#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define matrix vector<vector<long long> >

// 斐波那契
int mod=1e9+7;
matrix matrixMulit(matrix& a, matrix& b){
  matrix ans(a.size(),vector<ll>(b[0].size(),0));
  for(int i=0;i<ans.size();++i){
    for(int j=0;j<ans[0].size();++j){
      for(int k=0;k<a[0].size();++k){
        ans[i][j]+=(a[i][k]*b[k][j]),ans[i][j]%=mod;
      }
    }
  }
  return ans;
}

matrix pow(matrix a, ll p){ // 将矩阵自乘
  matrix ans(a.size(),vector<ll>(a[0].size(),0));
  for(int i=0;i<ans.size();++i) ans[i][i]=1; // 初始化成单位矩阵
  while(p){
    if(p%2) ans=matrixMulit(ans,a);
    a=matrixMulit(a,a);
    p=p>>1;
  }
  return ans;
}


int main(void){
  ll n;
  cin>>n;
  if(n==1) {cout<<1<<endl; return 0;}
  if(n==2) {cout<<2<<endl; return 0;}
  if(n==3) {cout<<3<<endl; return 0;}
  vector<ll> t1(3,0), t2(3,0), t3(3,0);
  t1[0]=1,t1[1]=1,t1[2]=0;
  t2[0]=0,t2[1]=0,t2[2]=1;
  t3[0]=1,t3[1]=0,t3[2]=0;
  matrix a(3,vector<ll>());
  a[0]=t1,a[1]=t2,a[2]=t3;
  a = pow(a, n-3);
  t1[0]=3,t1[1]=2,t1[2]=1; // 初始项不同
  matrix ori(1,t1);
  a = matrixMulit(ori, a);
  cout<<a[0][0]<<endl;
  return 0;
}