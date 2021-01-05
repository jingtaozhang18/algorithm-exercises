// https://leetcode-cn.com/problems/positions-of-large-groups/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
      int i, t=0;
      char c=0;
      vector<vector<int>> ans;
      for(i=0;i<s.size();++i){
        if(s[i]==c){
          ++t;
          continue;
        }else{
          if(t>=3){
            ans.push_back(vector<int>{i-t, i-1});
          }
          c=s[i], t=1;
        }
      }
      if(t>=3){
        ans.push_back(vector<int>{i-t, i-1});
      }
      return ans;
    }
};