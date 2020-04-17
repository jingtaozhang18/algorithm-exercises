#include<bits/stdc++.h>
using namespace std;

int main(void){
  int lenA,lenB;
  string a,b;
  cin>>lenA>>lenB;
  if(lenA!=lenB){
    printf("NO\n");
    return 0;
  }
  cin>>a>>b;
  a+=a;
  if(a.find(b)!=string::npos){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}