#include<bits/stdc++.h>
using namespace std;

int func(int all, int preLine, int leftDia, int rightDia){
  if(all==preLine) return 1;
  int pos=all & (~(preLine | leftDia | rightDia)); // 当前可取位置
  int ans=0;
  while(pos){
    int mostRight=pos & (~pos+1); // 只保留最右侧的1
    pos=pos&(~mostRight); // 删掉最右侧的1
    ans+=func(all, (preLine|mostRight), ((leftDia<<1)|(mostRight<<1)), ((rightDia>>1)|(mostRight>>1)));
  }
  return ans;
}

int main(void){  
  int n;
  scanf("%d", &n);
  int all=n==32?-1:(1<<n)-1;
  printf("%d\n",func(all, 0, 0, 0));
  return 0;
}