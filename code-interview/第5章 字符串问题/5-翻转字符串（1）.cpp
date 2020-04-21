#include<bits/stdc++.h>
using namespace std;

void func(string& str, int start, int end){
  while(start<end) swap(str[start++], str[end--]);
}


int main(void){
  int i, pre=0;
  string str;
  getline(cin, str);
  for(i=0;i<str.size();++i){
    if(str[i]==' '){
      func(str,pre,i-1);
      pre=i+1;
    }
  }
  func(str,pre,i-1);
  cout<<str<<endl;
  return 0;
}