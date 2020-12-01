// https://leetcode-cn.com/problems/candy/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
      int i, size=ratings.size(), ans;
      vector<int> L(size, 1);
      vector<int> R(size, 1);
      for(i=1;i<size;++i) if(ratings[i]>ratings[i-1]) L[i]=L[i-1]+1;
      for(i=size-2;i>=0;--i) if(ratings[i]>ratings[i+1]) R[i]=R[i+1]+1;
      for(i=0,ans=0;i<size;++i) ans+=max(L[i], R[i]);
      return ans;
    }
};