// https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int size=nums.size();
      // if(nums[0]>=0) return nums[j--]*nums[j--]*nums[j--]; // 不需要考虑从每种情况出发考虑
      return max(nums[size-1]*nums[size-2]*nums[size-3], nums[0]*nums[1]*nums[size-1]);
    }
};