// https://leetcode-cn.com/problems/kLl5u1/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      if (numbers[i] + numbers[j] == target) {
        return {i, j};
      } else if (numbers[i] + numbers[j] > target) {
        --j;
      } else {
        ++i;
      }
    }
    return {-1, -1};
  }
};