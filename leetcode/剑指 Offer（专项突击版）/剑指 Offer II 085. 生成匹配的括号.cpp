// https://leetcode-cn.com/problems/IDBivT/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> ans;
  string path;
  void calc(int i, int left, int right) {
    if (i == path.size()) {
      ans.push_back(path);
      return;
    }
    if (left) {
      path[i] = '(';
      calc(i + 1, left - 1, right + 1);
    }
    if (right) {
      path[i] = ')';
      calc(i + 1, left, right - 1);
    }
  }
  vector<string> generateParenthesis(int n) {
    path = string(n * 2, ' ');
    calc(0, n, 0);
    return ans;
  }
};