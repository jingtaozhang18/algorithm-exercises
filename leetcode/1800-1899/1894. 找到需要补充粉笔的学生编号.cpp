// https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int kk) {
    int i, n = chalk.size(), left = 0, right, mid;
    long long x, k = kk;
    vector<long long> acc(n);
    for (i = 0; i < n; ++i)
      acc[i] = ((i > 0) ? acc[i - 1] : 0) + chalk[i];  // 累加数组
    right = (k / acc[n - 1] + 1) * n - 1;
    while (left <= right) {
      mid = (left + right) >> 1;
      x = acc[n - 1] * (mid / n) + acc[mid % n];
      if (k - x < chalk[mid % n])
        right = mid - 1;
      else
        left = mid + 1;
    }
    while (true) {
      ++right;
      x = acc[n - 1] * (right / n) + acc[right % n];
      if (k >= x)
        continue;
      else
        return right % n;
    }
    return -1;
  }
};