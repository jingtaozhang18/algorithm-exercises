// https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<int> acc;
    int x = 0;
    for (auto& e : arr) {
      x += e;
      acc.push_back(x);
    }
    auto findIndex = [&arr](int t) {
      int left = 0, right = arr.size() - 1, mid;
      while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] <= t) left = mid + 1;
        else right = mid - 1;
      }
      return left;
    };
    int left = 0, right = *arr.rbegin(), mid, ansV = INT_MAX, ans = INT_MAX;
    while (left <= right) {
      mid = (left + right) / 2;
      int j = findIndex(mid);
      if (j > 0) x = acc[j - 1];
      else x = 0;
      x += (arr.size() - j) * mid;
      if (x == target) return mid;
      else if (x < target) left = mid + 1;
      else right = mid - 1;
      if (abs(x - target) <= ansV) {
        if (abs(x - target) == ansV) ans = min(ans, mid);
        else ans = mid;
        ansV = abs(x - target);

      }
    }
    return ans;
  }
};
