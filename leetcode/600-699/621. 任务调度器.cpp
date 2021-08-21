// https://leetcode-cn.com/problems/task-scheduler/
#include <bits/stdc++.h>
using namespace std;

// 参考https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int len = tasks.size();
    vector<int> vec(26);
    for (char c : tasks) ++vec[c - 'A'];
    sort(vec.begin(), vec.end(), [](int& x, int& y) { return x > y; });
    int cnt = 1;
    while (cnt < vec.size() && vec[cnt] == vec[0]) cnt++;
    return max(len, cnt + (n + 1) * (vec[0] - 1));
  }
};