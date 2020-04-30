#include<bits/stdc++.h>
using namespace std;

// 剥洋葱的策略，依据最长回文序列的指导，一层层的修复str的回文结构
int main(void){
  string str, strips;
  cin>>str>>strips;
  int zl=0,zr=strips.size()-1; // strips的左右两侧
  int sl=0,sr=str.size()-1; // str需要处理的原字符串部分
  int i,j,k,left; // i定位到str[i] == strips[zl], j同理
  while(zl<=zr){
    left=0;
    for(i=sl;str[i]!=strips[zl];++i);
    for(j=sr;str[j]!=strips[zr];--j);
    for(k=1;i-k>=sl;++k) str.insert(sr+k, 1, str[i-k]);
    for(k=0;sr-k>j;++k){
      str.insert(i, 1, str[sr-k]);
      i++,j++,sr++;
    }
    sl=i+1,sr=j-1,zl++,zr--;
  }
  cout<<str<<endl;
  return 0;
}