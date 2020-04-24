#include<bits/stdc++.h>
using namespace std;

int main(void){
  string str;
  getline(cin, str);
  int i,j,count=0;
  for(i=0;i<str.size();++i) if(str[i]==' ') count++;
  j=str.size()-1; // 原字符串指针
  str.resize(str.size()+count*2, 0);
  i=str.size()-1; // 新字符串指针
  for(;j>=0;--j){
    if(str[j]!=' ') str[i--]=str[j];
    else{
      str[i--]='0',str[i--]='2',str[i--]='%';
    }
  }
  cout<<str<<endl;
  return 0;
}