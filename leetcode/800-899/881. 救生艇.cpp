// https://leetcode-cn.com/problems/boats-to-save-people/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int ans = 0;
    int i, n = people.size(), j = n - 1;
    for (i = 0; i < j; ++i) {
      while (j > i && people[i] + people[j] > limit) {
        --j;
        ++ans;
      }
      --j;
      ++ans;
    }
    if (i == j) ++ans;
    return ans;
  }
};
