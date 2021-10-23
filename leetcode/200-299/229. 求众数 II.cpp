// https://leetcode-cn.com/problems/majority-element-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int e1, e2, v1 = 0, v2 = 0;
    for (auto& ele : nums) {
      if (v1 > 0 && ele == e1) ++v1;
      else if (v2 > 0 && ele == e2) ++v2;
      else if (v1 == 0) v1 = 1, e1 = ele;
      else if (v2 == 0) v2 = 1, e2 = ele;
      else --v1, --v2;
    }
    int cnt1 = 0, cnt2 = 0;
    for (auto& ele : nums) {
      if (v1 && ele == e1) ++cnt1;
      if (v2 && ele == e2) ++cnt2;
    }
    vector<int> ans;
    if (cnt1 * 3 > nums.size()) ans.push_back(e1);
    if (cnt2 * 3 > nums.size()) ans.push_back(e2);
    return ans;
  }
};