#include<iostream>
using namespace std;
int mem[10000];
int n,m;
int main(void){
  cin>>n>>m;
  int i,index;
  for(i=0;i<n;++i){ // 构建循环
    mem[i]=i+1;
  }
  i--;
  mem[i]=0;
  index=1;
  while(mem[i]!=i){
    if(index==m){
//      cout << "del" << mem[i]<<endl;
      mem[i]=mem[mem[i]],index=1;
    } 
    i=mem[i];
    index++;
  }
  cout << i+1 <<endl;
  return 0;
}