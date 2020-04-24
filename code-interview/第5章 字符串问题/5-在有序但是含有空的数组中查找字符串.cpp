#include<bits/stdc++.h>
using namespace std;
// https://www.nowcoder.com/practice/92c172ef7c6d4ccc8f3103c3bc36cae2?tpId=101&tqId=33167&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
// 看书才搞懂题意，练习二分查找的使用

string mem[100000];
int main(void){
  int n,i;
  char buff[16];
  memset(buff,0,sizeof buff);
  scanf("%d%s",&n, &buff[0]);
  string tar(buff);
  for(i=0;i<n;++i) {
    memset(buff,0,sizeof(buff));
    scanf("%s",&buff[0]);
    mem[i]=string(buff);
  }
  // 二分查找
  int L=0,R=n-1,M,ans=-1;
  while(L<=R){
    M=(L+R)>>1;
    if(mem[M]==tar) ans=M,R=M-1; //继续向左查找
    else if(mem[M]!="0"){ // 正常二分
      if(mem[M]>tar) R=M-1;
      else L=M+1;
    }else{ // 特殊遍历
      for(i=M-1;i>=L;--i)
        if(mem[i]!="0"){
          if(mem[i]==tar) ans=i,R=i-1;
          else if(mem[i]>tar) R=i-1;
          else L=M+1;
          break;
        }
      if(i==L-1) L=M+1;
    }
  }
  printf("%d\n",ans);
  return 0;
}