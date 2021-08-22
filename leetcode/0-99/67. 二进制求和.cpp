// https://leetcode-cn.com/problems/add-binary/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    bool jin = false;
    int m = a.size(), n = b.size(), i, j, k;
    string ans(max(m, n), ' ');
    for (i = m - 1, j = n - 1, k = max(i, j); i >= 0 || j >= 0; --i, --j) {
      char ca = i >= 0 ? a[i] : '0';
      char cb = j >= 0 ? b[j] : '0';
      short x = short(ca - '0') + short(cb - '0') + jin;
      if (x == 0) {
        ans[k--] = '0';
        jin = false;
      } else if (x == 1) {
        ans[k--] = '1';
        jin = false;
      } else if (x == 2) {
        ans[k--] = '0';
        jin = true;
      } else {
        ans[k--] = '1';
        jin = true;
      }
    }
    if (jin)
      return '1' + ans;
    else
      return ans;
  }
};