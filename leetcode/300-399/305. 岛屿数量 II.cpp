// https://leetcode-cn.com/problems/number-of-islands-ii/
#include<bits/stdc++.h>
using namespace std;

struct UnionStruct {
  unordered_map<int, int> arr;
  int n;
  UnionStruct(int n) :n(n) {
  }
  int find(int idx) {
    if (arr.find(idx) == arr.end() || arr[idx] == idx) return idx;
    return arr[idx] = find(arr[idx]);
  }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      arr[x] = y;
      --n;
    }
  }
};
class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    unordered_set<int> arr;
    vector<int> ans;
    int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
    int x, y, k, okey, key;
    UnionStruct us(m * n);
    for (auto& e : positions) {
      okey = e[0] * n + e[1];
      for (k = 0;k < 4;++k) {
        x = e[0] + dir[k][0];
        y = e[1] + dir[k][1];
        if (x >= 0 && x < m && y >= 0 && y < n) {
          key = x * n + y;
          if (arr.find(key) != arr.end()) {
            us.merge(key, okey);
          }
        }
      }
      arr.insert(okey);
      ans.push_back(us.n - (m * n - arr.size()));
    }
    return ans;
  }
};