#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n, k, i,pre;
  string str;
  cin>>n>>k>>str;
  for(i=k-1;i>=0&&str[i]>='A'&&str[i]<='Z';--i);
  if((k-i-1)%2) cout<<str[k-1]<<str[k]<<endl;
  else 
     if(k+1<n&&str[k]>='A'&&str[k]<='Z') cout<<str[k]<<str[k+1]<<endl; 
     else cout<<str[k]<<endl;
  return 0;
}