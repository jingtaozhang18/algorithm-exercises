// https://leetcode-cn.com/problems/M99OJA/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<bool>> arr;
  vector<vector<string>> ans;
  int m;
  void calc(int i, string& s, vector<string>& path) {
    if (i == m)
      ans.push_back(path);
    else {
      for (int j = i + 1; j <= m; ++j) {
        if (arr[i][j - 1]) {
          path.push_back(s.substr(i, j - i));
          calc(j, s, path);
          path.pop_back();
        }
      }
    }
  }
  vector<vector<string>> partition(string s) {
    m = s.size();
    int i, j, d;
    arr = vector<vector<bool>>(m, vector<bool>(m, 0));
    for (d = 0; d < m; ++d) {
      for (i = 0; i < m - d; ++i) {
        j = i + d;
        if (d <= 1)
          arr[i][j] = (s[i] == s[j]);
        else {
          arr[i][j] = (s[i] == s[j]) && arr[i + 1][j - 1];
        }
      }
    }
    vector<string> path;
    calc(0, s, path);
    return ans;
  }
};