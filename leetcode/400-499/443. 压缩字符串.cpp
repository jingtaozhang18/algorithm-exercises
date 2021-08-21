// https://leetcode-cn.com/problems/string-compression/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int jcalc(int x) {
    if (x == 1) return 0;
    int ans = 0;
    while (x) {
      ++ans;
      x /= 10;
    }
    return ans;
  }
  int compress(vector<char>& chars) {
    int ts, i, j = 0, k, a, m = chars.size();
    if (!m) return 0;
    char c = chars[0];
    ts = 1;
    for (i = 1; i <= m; ++i) {
      if (i < m && c == chars[i]) {
        ts++;
      } else {
        // 结算
        chars[j++] = c;
        a = j + jcalc(ts);
        for (k = a - 1; k >= j; --k) {
          chars[k] = (ts % 10) + '0';
          ts /= 10;
        }
        j = a;
        if (i < m) {
          ts = 1;
          c = chars[i];
        }
      }
    }
    return j;
  }
};