// https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    priority_queue<pair<double, pair<int, int>>> que;
    int i, j, m = arr.size();
    for (i = 0;i < m;++i) {
      for (j = i + 1;j < m;++j) {
        que.push(make_pair(double(arr[i]) / arr[j], make_pair(arr[i], arr[j])));
        if (que.size() > k) {
          que.pop();
        }
      }
    }
    return { que.top().second.first, que.top().second.second };
  }
};