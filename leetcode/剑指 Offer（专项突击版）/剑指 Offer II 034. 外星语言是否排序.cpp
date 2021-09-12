// https://leetcode-cn.com/problems/lwyVBB/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int mp[200];
  bool calc(string& a, string& b) {  // a<=b is true?
    int i = 0, j = 0, m = a.size(), n = b.size();
    while (i < m && j < n) {
      if (mp[a[i]] < mp[b[j]]) return true;
      if (mp[a[i]] > mp[b[j]]) return false;
      ++i, ++j;
    }
    return m <= n;
  }
  bool isAlienSorted(vector<string>& words, string order) {
    int i, n = words.size();
    for (i = 0; i < order.size(); ++i) mp[order[i]] = i;
    for (i = 1; i < n; ++i) {
      if (!calc(words[i - 1], words[i])) return false;
    }
    return true;
  }
};