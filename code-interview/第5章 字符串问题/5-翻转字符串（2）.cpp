#include<bits/stdc++.h>
using namespace std;

void reverse(string& str, int start, int end){
  while(start<end) swap(str[start++], str[end--]);
}

int main(void){
  int n;
  scanf("%d", &n);
  string str;
  getline(cin, str); // 把size的那行读掉
  getline(cin, str); // 
  reverse(str,0,n-1);
  reverse(str,n,str.size()-1);
  reverse(str,0,str.size()-1);
  cout<<str<<endl;
  return 0;
}