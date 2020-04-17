#include<bits/stdc++.h>
using namespace std;

int mema[256];
int memb[256];

int main(void){
  int na,nb,i;
  string a,b;
  cin>>na>>nb;
  if(na!=nb){
    printf("false\n");
    return 0;
  }
  cin>>a>>b;
  for(i=0;i<na;++i)mema[a[i]]++;
  for(i=0;i<nb;++i)memb[b[i]]++;
  for(i=0;i<256;++i)
    if(mema[i]!=memb[i]){
      printf("false\n");
      return 0;
    }
  printf("true\n");
  return 0;
}