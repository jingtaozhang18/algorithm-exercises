#include<bits/stdc++.h>
using namespace std;
  
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,k,i,j,m;
  cin>>n>>k;
  vector<int> arr(n);
  for(i=0;i<n;++i) cin>>arr[i];
  for(m=0;m<n-2;){
    for(i=m+1,j=n-1;i<j;){
      if(arr[i]+arr[j]<k-arr[m]) do i++; while(i<j&&arr[i]==arr[i-1]); // 每种数字只走一次
      else if(arr[i]+arr[j]>k-arr[m]) do j--; while(j>i&&arr[j]==arr[j+1]);
      else{
        cout<<arr[m]<<" "<<arr[i]<<" "<<arr[j]<<endl;
        do i++; while(i<j&&arr[i]==arr[i-1]);
        do j--; while(j>i&&arr[j]==arr[j+1]);
      }
    }
    do m++; while(m<n&&arr[m]==arr[m-1]);
  }
  return 0;
}