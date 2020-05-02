#include<bits/stdc++.h>
using namespace std;
// string a and string b 若a+b的字典序比b+a的字典序更小，a就更应该在前面
string arr[100002];

int cmp(const string& a, const string& b){
  return (a+b) < (b+a);
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,i;
  cin>>n;
  for(i=0;i<n;++i) cin>>arr[i];
  sort(arr,arr+n,cmp);
  for(i=0;i<n;++i) cout<<arr[i];
  cout<<endl;
  return 0;
}