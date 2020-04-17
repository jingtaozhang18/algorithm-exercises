#include<bits/stdc++.h>
using namespace std;

int main(void){
  string a;
  cin>>a;
  int i=0;
  long long value=0;
  bool flag=false;
  if(a[i]=='-') flag=true,i++;
  if(a[i]=='0') {cout<<0<<endl; return 0;} // 最开始的字符是0,或者真的只有一个0
  for(;i<a.size();++i){
    if('0'<=a[i]&&a[i]<='9'){
      value*=10,value+=a[i]-'0';
      if((!flag&&value>INT_MAX)||(flag&&value-1>INT_MAX)){
        cout<<0<<endl;
        return 0;
      }
    }else{
      cout<<0<<endl;
      return 0;
    }
  }
  value = flag?-1*value:value;
  cout<<value<<endl;
  return 0;
}