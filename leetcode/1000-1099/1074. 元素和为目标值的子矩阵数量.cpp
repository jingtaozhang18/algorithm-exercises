// https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/submissions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int m=matrix.size(), n=matrix[0].size(), i, j, k, ans=0, x;
      vector<int> acc(n);
      unordered_map<int, int> mp;
      for(i=0;i<m;++i){
        for(j=0;j<n;++j) acc[j]=0;
        for(j=i;j<m;++j){
          mp.clear(); mp[0]=1;
          for(k=0;k<n;++k) acc[k]+=matrix[j][k];
          for(x=k=0;k<n;++k){
            x+=acc[k];
            auto p=mp.find(x-target);
            if(p!=mp.end()) ans+=p->second;
            mp[x]++;
          }
        }
      }
      return ans;
    }
};