#include<bits/stdc++.h>
using namespace std;

int arr[100001];
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(0);
  int n,k,i,j,ans=-1;
  cin>>n>>k;
  for(i=1;i<=n;++i) cin>>arr[i]; // 从1开始计数
  for(i=1;i<=n;++i) arr[i]+=arr[i-1]; // 累加和计算
  for(i=1,j=1;i<=n&&j<=n;){ // [i,j]部分累加和
    if(arr[j]-arr[i-1]<k) j++;
    else if(arr[j]-arr[i-1]>k) i++;
    else{
      ans=max(ans,j-i+1);
      i++,j++;
    }
  }
  cout<<ans<<endl;
  return 0;
}