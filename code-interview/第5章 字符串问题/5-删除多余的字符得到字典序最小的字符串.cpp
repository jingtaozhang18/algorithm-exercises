#include<bits/stdc++.h>
using namespace std;

int mem[26]; // 26个字母计数
int main(void){
  string in;
  string out(27,0);
  cin>>in;
  int i,j,L,k,n;
  for(i=0;i<in.size();++i) mem[in[i]-'a']++; // 为字符计数
  i=j=L=0; // in的下标，out的下标，in的最左有用位置
  while(i<in.size()){
    mem[in[i]-'a']--; // 减掉一次计数
    if(mem[in[i]-'a']==0){ // 有字符in[i]消失，必须从[L,i]的位置产出一个字符
//      printf("i:(%d)",i);
      n=i; //初始化最小字典序值
      for(k=i-1;k>=L;--k) if(mem[in[k]-'a']>=0&&in[k]<=in[n]) n=k; // 相同字符取位置最靠前的
      out[j++]=in[n],mem[in[n]-'a']=-1; // 输出最小字典序的字符，并更新最左有效边界，并不再考虑该字符
      for(k=n+1;k<=i;k++) if(mem[in[k]-'a']>=0) mem[in[k]-'a']++; // 重新计数没有被删掉的部分
      i=L=n+1;
//      printf("%d(%d)",L,mem[in[i]-'a']);
    }else i++;
  }
  cout<<out.substr(0,j)<<endl;
  return 0;
}