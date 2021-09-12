// https://leetcode-cn.com/problems/sfvd7V/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (auto& str : strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      mp[tmp].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto p : mp) {
      vector<string> t;
      for (auto& e : p.second) {
        t.push_back(e);
      }
      ans.push_back(t);
    }
    return ans;
  }
};