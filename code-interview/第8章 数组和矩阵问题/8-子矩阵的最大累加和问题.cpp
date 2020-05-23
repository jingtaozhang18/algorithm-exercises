#include<bits/stdc++.h>
using namespace std;

int arr[200][200];
int tmp[200];
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m,i,j,k,ta,ans=INT_MIN;
  cin>>n>>m;
  for(i=0;i<n;++i)for(j=0;j<m;++j)cin>>arr[i][j];
  for(k=0;k<n;++k){
    memset(tmp, 0, sizeof(int)*m);
    for(i=k;i<n;++i){
      for(j=0;j<m;++j) tmp[j]+=arr[i][j];
      //. 找出tmp中的最大连续数组
      ta=tmp[0],ans=max(ans, ta);
      for(j=1;j<m;++j) ta=max(tmp[j], ta+tmp[j]), ans=max(ans, ta);
    }
  }
  cout<<ans<<endl;
  return 0;
}