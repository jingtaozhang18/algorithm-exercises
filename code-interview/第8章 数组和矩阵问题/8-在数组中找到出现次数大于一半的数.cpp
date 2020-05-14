#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  int n,i,v,t;
  cin>>n;
  for(i=0;i<n;++i) cin>>arr[i];
  v=arr[0],t=1;
  for(i=1;i<n;++i){
    if(arr[i]==v)t++;
    else{
      if(!--t) v=arr[i],t=1;
    }
  }
  t=0;
  for(i=1;i<n;++i) if(arr[i]==v) t++;
  if(t>(n>>1)) cout<<v<<endl;
  else cout<<-1<<endl;
  return 0;
}