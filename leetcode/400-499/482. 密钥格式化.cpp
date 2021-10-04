// https://leetcode-cn.com/problems/license-key-formatting/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    int acc = 0, i, j, a, x;
    for (auto& c : s)
      if (c != '-') ++acc;
    if (acc == 0) return "";
    string ans(acc + acc / k - 1 + (acc % k ? 1 : 0), ' ');
    x = acc % k;
    i = j = 0;
    if (x) {
      for (j = 0; j < x; ++j) {
        while (s[i] == '-') ++i;
        if (s[i] >= 'a' && s[i] <= 'z')
          ans[j] = s[i++] + 'A' - 'a';
        else
          ans[j] = s[i++];
      }
      if (j < ans.size()) ans[j++] = '-';
    }
    a = k;
    for (; i < s.size(); ++i) {
      if (s[i] == '-') continue;
      if (s[i] >= 'a' && s[i] <= 'z')
        ans[j++] = s[i] + 'A' - 'a';
      else
        ans[j++] = s[i];
      --a;
      if (a == 0 && j < ans.size()) ans[j++] = '-', a = k;
    }
    return ans;
  }
};
