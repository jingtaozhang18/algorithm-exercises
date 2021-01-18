// https://leetcode-cn.com/problems/accounts-merge/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      unordered_map<string, int> e2id;
      unordered_map<int, set<string>> id2e;
      set<int> lx;
      int i,j=0,k;
      for(auto e:accounts){
        lx=set<int>();
        for(i=1;i<e.size();++i){
          if(e2id.find(e[i])!=e2id.end()&&e2id[e[i]]!=j) lx.insert(e2id[e[i]]);
          e2id[e[i]]=j; id2e[j].insert(e[i]);
        }
        for(auto id:lx){
          for(auto email:id2e[id]) {e2id[email]=j; id2e[j].insert(email);}
          id2e.erase(id2e.find(id));
        }
        ++j;
      }
      vector<vector<string>> ans;
      vector<string> t;
      for(auto e:id2e){
        t=vector<string>{accounts[e.first][0]};
        for(auto ee:e.second){
          t.push_back(ee);
        }
        ans.push_back(t);
      }
      return ans;
    }
};