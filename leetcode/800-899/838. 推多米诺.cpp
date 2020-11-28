// https://leetcode-cn.com/problems/push-dominoes/
#include<bits/stdc++.h>
using namespace std;

// 从受力的角度进行分析
class Solution {
public:
    string pushDominoes(string dominoes) {
      bool flag=false;
      int i,size=dominoes.size(),t;
      vector<int> R(size, INT_MAX); // 左边最近向右倒的牌距离该位置的距离
      vector<int> L(size, INT_MAX); // 右边最近向左倒的牌距离该位置的距离
      for(flag=false,i=0;i<size;++i){ 
        if(dominoes[i]=='R') t=i,flag=true; 
        else if(dominoes[i]=='L') flag=false; 
        if(flag) R[i]=i-t;
      }
      for(flag=false,i=size-1;i>=0;--i){
        if(dominoes[i]=='L') t=i, flag=true;
        else if(dominoes[i]=='R') flag=false;
        if(flag) L[i]=t-i;
      }
      for(i=0;i<size;++i){
        // cout<<i<<" "<<R[i]<<" "<<L[i]<<endl;
        if(R[i]==L[i]) dominoes[i]='.';
        else if(R[i]<L[i]) dominoes[i]='R';
        else dominoes[i]='L';
      }
      return dominoes;
    }
};