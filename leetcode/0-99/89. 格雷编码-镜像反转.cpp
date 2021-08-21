// https://leetcode-cn.com/problems/gray-code/
#include <bits/stdc++.h>
using namespace std;

// 参考题解
// https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> ans(1 << n);
    int i, j, x;
    ans[0] = 0;
    if (n == 0) return ans;
    ans[1] = 1;
    i = 2;
    x = 2;
    while (--n) {
      for (j = i - 1; j >= 0; --j) {
        ans[i++] = (x + ans[j]);
      }
      x <<= 1;
    }
    return ans;
  }
};