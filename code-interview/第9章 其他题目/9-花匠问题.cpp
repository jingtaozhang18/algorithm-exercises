#include<bits/stdc++.h>
using namespace std;

bool needW(vector<long long>& arr, long long lt, long long lw){ // 返回在lt时间内lw个工人的是否可以完成, 输入需要保证max(arr[i])<lt
  long long nw=0, i, acct=lt; //现在需要的工人数量
  for(i=0;i<arr.size();++i){
    acct+=arr[i];
    if(acct<=lt) continue;
    else {
      nw++;
      acct=arr[i];
      if(nw>lw) return false;
    }
  }
  return nw<=lw;
}

long long jfind(vector<long long> &arr, long long n){ // 画画需要的时间，花匠人数, n<arr.size()
  long long i,l=0,r=0,m;
  for(i=0;i<arr.size();++i) r+=arr[i],l=max(l,arr[i]);
  // cout<<l<<" "<<r<<endl;
  while(l<r){
    m=(l+r)>>1;
    if(needW(arr, m, n)){
      // cout<<"judge: "<<m<<" ok"<<endl;
      r=m;
    }else{ // 更久的时间
      l=m+1;
      // cout<<"judge: "<<m<<" no"<<endl;
    }
  }
  return l;
}

int main(void){
  int n;
  long long m, i, v, ans=0;
  cin>>n>>m;
  if(m>n){for(i=0;i<n;++i){cin>>v; ans=max(ans, v);}cout<<ans<<endl;return 0;}
  vector<long long> arr(n);
  for(i=0;i<n;++i){
    cin>>v;
    arr[i]=v;
  }
  cout<<jfind(arr, m)<<endl;
  return 0;
}