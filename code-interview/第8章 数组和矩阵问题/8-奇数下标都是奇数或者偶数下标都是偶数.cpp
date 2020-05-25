#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  int n,i,ou=0,ji=0;
  cin>>n;
  for(i=0;i<n;++i){cin>>arr[i]; if(arr[i]%2) ji++; else ou++;}
  if(ou>ji){ // 偶数数量多，就让所有偶数位置上都是偶数
    ou=0;
    for(i=1;i<n;i+=2){
      while(arr[ou]%2==0 && ou<n) ou+=2;
      if(! (ou<n)) break;
      if(arr[i]%2==0) swap(arr[i], arr[ou]);
    }
  }else{
    ji=1;
    for(i=0;i<n;i+=2){
      while(arr[ji]%2!=0 && ji<n) ji+=2;
      if(! (ji<n)) break;
      if(arr[i]%2==1) swap(arr[i], arr[ji]);
    }
  }
  for(i=0;i<n;++i) cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}