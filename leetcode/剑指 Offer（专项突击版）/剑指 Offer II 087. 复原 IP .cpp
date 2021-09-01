// https://leetcode-cn.com/problems/0on3uN/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> ans;
  vector<int> path;
  void calc(string& s, int i) {
    int j, x = 0;
    if (i == s.size()) {
      if (path.size() == 4) {
        string s;
        for (j = 0; j < path.size(); ++j) {
          if (j == path.size() - 1) {
            s += to_string(path[j]);
          } else {
            s += to_string(path[j]) + '.';
          }
        }
        ans.push_back(s);
      }
      return;
    }
    if (path.size() == 4) return;
    j = i;
    do {
      x *= 10, x += s[j] - '0';
      ++j;
      if (x <= 255) {
        path.push_back(x);
        calc(s, j);
        path.pop_back();
      } else {
        break;
      }
    } while (j < s.size() && x);
  }
  vector<string> restoreIpAddresses(string s) {
    calc(s, 0);
    return ans;
  }
};