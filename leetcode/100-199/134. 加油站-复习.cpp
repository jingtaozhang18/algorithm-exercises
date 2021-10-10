// https://leetcode-cn.com/problems/gas-station/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int i, m = gas.size(), start = -1, maxLeft, need, left, maxPos, step;
    // 选择开始的位置麻烦了，随便一个>=0的位置都可以
    for (i = 0;i < m;++i) {
      gas[i] -= cost[i];
      if (start == -1) {
        maxLeft = gas[i];
        start = i;
      }
      else {
        if (gas[i] > maxLeft) {
          maxLeft = gas[i];
          start = i;
        }
      }
    }
    auto nextStep = [&m](int index) {return (index + 1) % m;};
    auto prefixStep = [&m](int index) {return (index - 1 + m) % m;};
    if (maxLeft < 0) return -1;
    // 从start开始
    need = 0;
    left = maxLeft;
    maxPos = start;
    step = 1;
    // 循环的次数和step计数的方法
    for (i = 0;i < m;++i) {
      while (gas[nextStep(maxPos)] + left >= 0 && step < m) {
        maxPos = nextStep(maxPos);
        left += gas[maxPos];
        ++step;
      }
      if (step == m && need == 0) return start;
      start = prefixStep(start);
      if (gas[start] >= need) left += gas[start] - need, need = 0;
      else need -= gas[start];
    }
    return -1;
  }
};