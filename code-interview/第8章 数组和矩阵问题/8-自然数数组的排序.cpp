#include<bits/stdc++.h>
using namespace std;

int arr[100001];
int main(void){
  int n,i;
  cin>>n;
  for(i=1;i<=n;++i)cin>>arr[i];
  for(i=1;i<=n;++i){
    while(arr[i]!=i){
      swap(arr[i],arr[arr[i]]);
    }
  }
  for(i=1;i<=n;++i)cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}