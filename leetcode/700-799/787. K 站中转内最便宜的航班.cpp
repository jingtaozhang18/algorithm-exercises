// https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    ++k;                                               // 可以跳的次数
    unordered_map<int, vector<pair<int, int>>> edges;  // index, cost
    for (auto &f : flights)
      edges[f[0]].push_back(make_pair(f[1], f[2]));  // 邻接链表
    queue<pair<int, int>> que;                       // index, level
    vector<vector<int>> arr(n, vector<int>(k + 1, INT_MAX));  // n个节点，每个节点上有k个level
    arr[src][0] = 0;                      // 最近距离
    que.push(make_pair(src, 0));
    int ans = INT_MAX;
    while (que.size()) {
      int x = que.front().first;
      int level = que.front().second;
      que.pop();
      int cost = arr[x][level];
      for (auto &edge : edges[x]) {
        if (cost + edge.second < arr[edge.first][level + 1]) {
          arr[edge.first][level + 1] = cost + edge.second;
          if (level + 1 < k) {
            que.push(make_pair(edge.first, level + 1));
          }
          if (edge.first == dst) {
            if (arr[edge.first][level + 1] < ans)
              ans = arr[edge.first][level + 1];
          }
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
