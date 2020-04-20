#include<bits/stdc++.h>
using namespace std;

int main(void){
  int i,count=0;
  string str;
  cin>>str;
  if(!str.size()) {printf("\n"); return 0;}
  char pre=0;
  for(i=0;i<str.size();++i){
    if(pre!=str[i]) {
      if(count)
        printf("%c_%d_",pre,count);
      pre=str[i],count=1;
    }else count++;
  }
  printf("%c_%d\n",pre,count);
  return 0;
}