// https://leetcode-cn.com/problems/pancake-sorting/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> ans;
  void addStep(int x) {
    if (x > 1) ans.push_back(x);
  }

  void pancake(vector<int>& arr, int k) { // in [0, k]
    int i;
    for (i = 0; i < k; ++i, --k) {
      swap(arr[i], arr[k]);
    }
  }

  void MoveMaxValueToFirstPlave(vector<int>& arr, int k) { // in [0, k)
    int i;
    int maxP, maxV = INT_MIN;
    for (i = 0; i < k; ++i) {
      if (arr[i] > maxV) {
        maxP = i, maxV = arr[i];
      }
    }
    if (maxP == 0) return;
    pancake(arr, maxP);
    addStep(maxP + 1);
  }
  void print(vector<int>& arr) {
    for (auto x : arr) {
      cout << x << " ";
    }
    cout << endl;
  }
  vector<int> pancakeSort(vector<int>& arr) {
    int j;
    for (j = arr.size(); j >= 1; --j) { // j is an expected Value, not a position.
      if (arr[j - 1] == j) {
        continue;
      }
      else {
        MoveMaxValueToFirstPlave(arr, j);
        pancake(arr, j - 1);
        addStep(j);
      }
      // cout<<j<<": ";
      // print(arr);
    }
    return ans;
  }
};