// https://leetcode-cn.com/problems/Jf1JuT/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> mp;
    unordered_map<char, int> degree;  // 边的入度
    unordered_set<char> st;
    int i;
    char c;
    auto calc = [&degree, &mp](string& a, string& b) -> bool {
      int i = 0, m = a.size(), n = b.size();
      while (i < m && i < n) {
        if (a[i] != b[i]) {
          if (mp[b[i]].find(a[i]) != mp[b[i]].end()) return false;
          if (mp[a[i]].find(b[i]) == mp[a[i]].end()) {
            ++degree[b[i]];
            mp[a[i]].insert(b[i]);
          }
          return true;
        }
        ++i;
      }
      return m <= n;
    };
    auto count = [&st](string& str) {
      for (auto& c : str) {
        st.insert(c);
      }
    };
    for (i = 0; i < words.size() - 1; ++i) {
      count(words[i]);
      if (calc(words[i], words[i + 1]) == false) return "";
    }
    count(words[i]);
    queue<char> que;
    for (auto& p : st) {
      if (degree[p] == 0) {
        que.push(p);
      }
    }
    string ans(st.size(), ' ');
    i = 0;
    while (que.size()) {
      c = que.front();
      que.pop();
      ans[i++] = c;
      for (auto x : mp[c]) {
        --degree[x];
        if (degree[x] == 0) {
          que.push(x);
        }
      }
    }
    return ans[ans.size() - 1] == ' ' ? "" : ans;
  }
};
