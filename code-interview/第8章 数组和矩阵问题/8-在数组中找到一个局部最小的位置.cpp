#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,i,start,end,mid;
  cin>>n;
  for(i=0;i<n;++i) cin>>arr[i];
  if(n==1) {cout<<0<<endl; return 0;}
  else if(arr[0]<arr[1]) {cout<<0<<endl; return 0;}
  else if(arr[n-1]<arr[n-2]) {cout<<n-1<<endl; return 0;}
  else{
    start=1,end=n-2;
    while(start<=end){
      mid=(start+end)>>1;
      if(arr[mid-1]<arr[mid]) end=mid-1;
      else if(arr[mid+1]<arr[mid]) start=mid+1;
      else{cout<<mid<<endl; return 0;}
    }
  }
  cout<<start<<endl;
  return 0;
}