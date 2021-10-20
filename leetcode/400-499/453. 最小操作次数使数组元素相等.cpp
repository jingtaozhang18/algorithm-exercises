// https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) {
    int min_v = *min_element(nums.begin(), nums.end());
    int count = 0;
    for (auto& e : nums) {
      count += e - min_v;
    }
    return count;
  }
};