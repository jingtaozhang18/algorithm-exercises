// https://leetcode-cn.com/problems/gas-station/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size(), i, init = -1;
    for (i = 0;i < size;++i) gas[i] -= cost[i], init = gas[i] >= 0 ? i : init; // 从i出发之后的盈余
    if (init == -1) return -1;
    int start = init, end = (init + 1) % size, need = 0, left = gas[init], step = 1;
    for (i = 0;i < size;++i) { // 保证start会经历到每个地方
      // 从当前位置向前出发，看能到达的最远的位置
      while (left + gas[end] >= 0 && step < size) left += gas[end], end = (end + 1) % size, ++step;
      if (step == size && need == 0) return start;
      start = start == 0 ? size - 1 : start - 1;
      if (gas[start] >= need) left += gas[start] - need, need = 0; // 错误点，left 需要减掉need
      else need -= gas[start];
    }
    return -1;
  }
};