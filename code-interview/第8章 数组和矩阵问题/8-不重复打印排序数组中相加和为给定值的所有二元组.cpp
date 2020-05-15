#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,k,i,j;
  cin>>n>>k;
  vector<int> arr(n);
  for(i=0;i<n;++i) cin>>arr[i];
  sort(arr.begin(), arr.end());
  for(i=0,j=n-1;i<j;){
    if(arr[i]+arr[j]<k) do i++; while(i<j&&arr[i]==arr[i-1]); // 每种数字只走一次
    else if(arr[i]+arr[j]>k) do j--; while(j>i&&arr[j]==arr[j+1]);
    else{
      cout<<arr[i]<<" "<<arr[j]<<endl;
      do i++; while(i<j&&arr[i]==arr[i-1]);
      do j--; while(j>i&&arr[j]==arr[j+1]);
    }
  }
  return 0;
}