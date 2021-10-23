// https://leetcode-cn.com/problems/ipo/
#include<bits/stdc++.h>
using namespace std;

struct node {
  int prof, cap;
  node(int p, int c) :prof(p), cap(c) {};
  bool operator<(const node& other) const {
    return this->cap > other.cap;
  }
};

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    priority_queue<pair<int, int>> que;
    int n = profits.size(), i;
    vector<node> arr;
    for (i = 0;i < n;++i) {
      arr.push_back(node(profits[i], capital[i]));
    }
    sort(arr.begin(), arr.end());
    i = n - 1;
    while (i >= 0 && arr[i].cap <= w) {
      que.emplace(arr[i].prof, arr[i].cap);
      --i;
    }
    while (que.size() && k--) {
      auto p = que.top();
      que.pop();
      // w -= p.second;
      w += p.first;
      while (i >= 0 && arr[i].cap <= w) {
        que.emplace(arr[i].prof, arr[i].cap);
        --i;
      }
    }
    return w;
  }
};