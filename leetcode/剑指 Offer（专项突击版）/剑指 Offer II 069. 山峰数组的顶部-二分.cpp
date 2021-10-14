// https://leetcode-cn.com/problems/B1IidL/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int left = 1, right = arr.size() - 2, mid, ans;
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
        return mid;
      }
      else if (arr[mid] > arr[mid + 1]) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
