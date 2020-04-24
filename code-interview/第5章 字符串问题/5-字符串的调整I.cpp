#include<bits/stdc++.h>
using namespace std;

int main(void){
  char str[100002];
  memset(str,0,sizeof str);
  scanf("%s", &str[0]);
  int i,j;
  for(i=0;str[i]!=0;++i); // 字符串长度
  j=i-1;
  for(i=i-1;i>=0;--i){
    if(str[i]!='*') str[j--]=str[i];
  }
  while(j>=0) str[j--]='*';
  cout<<str<<endl;
  return 0;
}