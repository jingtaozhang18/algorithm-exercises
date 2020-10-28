// https://www.nowcoder.com/practice/0639c9c82ca643d0b08a58ae40cad178?tpId=101&&tqId=33131&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

long long arr[1000002];
long long rmax[1000002];
int main(void){
  int n,i;
  long long lmax, ans=0;
  cin>>n;
  for(i=0;i<n;++i)cin>>arr[i];
  rmax[n-1]=arr[n-1];
  lmax=arr[0];
  for(i=n-2;i>0;--i)rmax[i]=max(arr[i],rmax[i+1]);
  for(i=1;i<n;++i)ans=max(ans,abs(lmax-rmax[i])),lmax=max(lmax,arr[i]);
  cout<<ans<<endl;
  return 0;
}