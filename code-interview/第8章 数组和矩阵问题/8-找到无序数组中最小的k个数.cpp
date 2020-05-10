#include<bits/stdc++.h>
using namespace std;

int mem[100000]; // 维护最大堆
int capacity=0; // 当前最大堆中的数量
int k; // 最大堆的大小
void add(int x){
  int i,fa,left,right;
  if(capacity<k){ // 直接放入元素
    mem[capacity]=x;
    capacity++;
    // 从下向上进行维护
    i=capacity-1;
    while(i){
      fa=(i-1)>>1;
      if(mem[fa]<mem[i]) swap(mem[fa], mem[i]);
      else break;
      i=fa;
    }
  }else if(x<mem[0]){
    mem[0]=x;
    // 从上向下进行维护
    i=0;
    while(i<capacity){
      left=(i<<1)+1;
      right=(i<<1)+2;
      if(left<capacity&&right<capacity){ // 左右孩子都存在
        if(mem[left]>=mem[right]&&mem[left]>mem[i]){swap(mem[left],mem[i]);i=left;}
        else if(mem[left]<mem[right]&&mem[right]>mem[i]){swap(mem[right],mem[i]);i=right;}
        else break;
      }else if(left<capacity){
        if(mem[left]>mem[i]){swap(mem[left],mem[i]);i=left;}
        else break;
      }else break;
    }
  }
}

int main(void){
  int n,t;
  cin>>n>>k;
  while(n--){cin>>t; add(t);}
  while(k) cout<<mem[--k]<<" ";
  return 0;
}