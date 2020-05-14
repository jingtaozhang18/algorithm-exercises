#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  int n,i,vMin,vMax,noMinIndex,noMaxIndex;
  cin>>n;
  for(i=0;i<n;++i)cin>>arr[i];
  noMinIndex=-1;
  vMin=arr[n-1];
  for(i=n-2;i>=0;--i){
    if(arr[i]<=vMin){
      vMin=arr[i];
    }else{
      noMinIndex=i;
    }
  }
  if(noMinIndex==-1) {cout<<0<<endl; return 0;}
  noMaxIndex=-1;
  vMax=arr[0];
  for(i=1;i<n;++i){
    if(arr[i]>=vMax){
      vMax=arr[i];
    }else{
      noMaxIndex=i;
    }
  }
  cout<<(noMaxIndex-noMinIndex+1)<<endl;
  return 0;
}