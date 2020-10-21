// https://www.nowcoder.com/practice/f92929ec6e5642a690e7c197b0c40e38?tpId=101&&tqId=33122&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

long long arr[1000002];
long long lmax[1000002];
long long rmax[1000002];

int main(void){
  int n,i;
  long long p,ans=0;
  cin>>n;
  for(i=0;i<n;++i)cin>>arr[i];
  for(p=0,i=0;i<n;++i){
    if(p>arr[i])lmax[i]=p;
    else lmax[i]=0,p=arr[i];
  }
  for(p=0,i=n-1;i>=0;--i){
    if(p>arr[i]) rmax[i]=p;
    else rmax[i]=0,p=arr[i];
  }
  for(i=0;i<n;++i){
    if(lmax[i]&&rmax[i])ans=ans+min(lmax[i], rmax[i])-arr[i];
  }
  cout<<ans<<endl;
  return 0;
}