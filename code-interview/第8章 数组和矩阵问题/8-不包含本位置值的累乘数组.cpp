#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100000];
ll l[100000];
ll r[100000];
int main(void){
  int n,i;
  ll P, a, b;
  cin>>n>>P;
  for(i=0;i<n;++i) {
    cin>>arr[i];
    if(!i) l[i]=arr[i];
    else l[i]=l[i-1]*arr[i],l[i]%=P;
  }
  for(i=n-1;i>=0;--i){
    if(i==n-1) r[i]=arr[i];
    else r[i]=r[i+1]*arr[i], r[i]%=P;
  }
  for(i=0;i<n;++i) {
    if(i) a=l[i-1];
    else a=1l;
    if(i!=n-1) b=r[i+1];
    else b=1l;
    cout<<((a*b)%P)<<" ";
  }
  cout<<endl;
  return 0;
}