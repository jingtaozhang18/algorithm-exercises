// https://leetcode-cn.com/problems/JFETK5/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int m = a.size(), n = b.size(), i = m - 1, j = n - 1, k = max(m, n) - 1,
        add = 0;
    string ans(max(m, n), ' ');
    while (i >= 0 || j >= 0) {
      if (i >= 0) add += a[i--] == '1' ? 1 : 0;
      if (j >= 0) add += b[j--] == '1' ? 1 : 0;
      if (add == 3 || add == 1)
        ans[k--] = '1';
      else
        ans[k--] = '0';
      if (add >= 2)
        add = 1;
      else
        add = 0;
    }
    if (add)
      return "1" + ans;
    else
      return ans;
  }
};