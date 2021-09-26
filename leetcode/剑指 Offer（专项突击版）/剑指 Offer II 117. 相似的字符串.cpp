// https://leetcode-cn.com/problems/H6lPxb/
#include <bits/stdc++.h>
using namespace std;

struct junion {
  int size;
  vector<int> arr;
  junion(int n) : size(n), arr(vector<int>(n)) {
    for (int i = 0; i < n; ++i) arr[i] = i;
  }
  int find(int i) {
    if (arr[i] != i) arr[i] = find(arr[i]);
    return arr[i];
  }
  void merge(int i, int j) {
    i = find(i), j = find(j);
    if (i != j) arr[i] = j, --size;
  }
};
class Solution {
 public:
  bool judge(string& a, string& b) {  // 是近似
    int i, size = a.size(), diff = 0;
    for (i = 0; i < size; ++i) {
      if (a[i] != b[i]) diff++;
      if (diff > 2) return false;
    }
    return true;
  }
  int numSimilarGroups(vector<string>& strs) {
    int i, j, size = strs.size();
    junion jun(size);
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        if (jun.find(i) != jun.find(j) && judge(strs[i], strs[j])) {
          jun.merge(i, j);
        }
      }
    }
    return jun.size;
  }
};
