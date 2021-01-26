// https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
      int i,size=dominoes.size(),ans=0,t;
      for(i=0;i<size;++i) sort(dominoes[i].begin(), dominoes[i].end());
      sort(dominoes.begin(), dominoes.end());
      for(i=1,t=1;i<=size;++i){
        if(i==size||dominoes[i-1]!=dominoes[i]){
          ans=ans+(t*(t-1))/2;
          t=1;
        }else{
          ++t;
        }
      }
      return ans;
    }
};