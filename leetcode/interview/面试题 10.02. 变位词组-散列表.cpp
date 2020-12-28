// https://leetcode-cn.com/problems/group-anagrams-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      unordered_map<string, vector<string>> mem; // 散列表，相比于排序的方式还是更快的
      string key;
      for(string s: strs)
      {
        key=s;
        sort(key.begin(), key.end());
        mem[key].push_back(s);
      }
      for(auto p:mem)
      {
        ans.push_back(p.second);
      }
      return ans;
    }
};