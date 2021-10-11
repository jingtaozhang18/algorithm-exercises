// https://leetcode-cn.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

// 比第一遍做的麻烦
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxLeft = *height.begin(), maxRight = *height.rbegin(), ans = 0;
        while (left <= right) {
            if (height[left] < height[right]) {
                ans += max(min(maxLeft, maxRight) - height[left], 0);
                ++left;
                if (left <= right)
                    maxLeft = max(maxLeft, height[left]);
            }
            else {
                ans += max(min(maxLeft, maxRight) - height[right], 0);
                --right;
                if (left <= right)
                    maxRight = max(maxRight, height[right]);
            }
        }
        return ans;
    }
};