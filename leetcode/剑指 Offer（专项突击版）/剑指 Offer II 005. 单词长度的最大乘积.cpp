// https://leetcode-cn.com/problems/aseY1I/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int m = words.size(), i, j, x, ans = 0;
    vector<int> record(m, 0);
    for (i = 0; i < m; ++i) {
      x = 0;
      for (j = 0; j < words[i].size(); ++j) {
        x |= 1 << (words[i][j] - 'a');
      }
      record[i] = x;
    }
    for (i = 0; i < m; ++i) {
      for (j = i + 1; j < m; ++j) {
        if (record[i] & record[j])
          ;
        else {
          ans = max(ans, (int)words[i].size() * (int)words[j].size());
        }
      }
    }
    return ans;
  }
};