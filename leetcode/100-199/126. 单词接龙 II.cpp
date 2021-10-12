// https://leetcode-cn.com/problems/word-ladder-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int m = wordList.size(), i, j, d;
    vector<vector<int>> edges(m, vector<int>()); // 边
    vector<int> minDistances(m, INT_MAX); // 最短距离
    vector<int> colors(m, 0); // 最短距离
    auto isNeig = [](string& a, string& b) {
      if (a.size() != b.size()) return false;
      int diff = 0, i;
      for (i = 0;i < a.size();++i) {
        if (a[i] != b[i]) ++diff;
      }
      return diff == 1;
    };
    int startIndex = m - 1, endIndex = -1;
    for (i = 0;i < m;++i) {
      if (endWord == wordList[i]) endIndex = i;
      for (j = i + 1;j < m;++j) {
        if (isNeig(wordList[i], wordList[j])) {
          edges[i].push_back(j);
          edges[j].push_back(i);
        }
      }
    }
    if (endIndex == -1) return {};
    // bfs 遍历，记录所有点到起点的最短距离
    colors[startIndex] = 1;
    queue<int> que;
    que.push(startIndex);
    minDistances[startIndex] = 0;
    while (que.size()) {
      i = que.front();
      que.pop();
      d = minDistances[i];
      for (auto& e : edges[i]) {
        if (colors[e] == 0) {
          colors[e] = 1;
          que.push(e);
          minDistances[e] = d + 1;
        }
      }
      colors[i] = 2;
    }
    if (minDistances[endIndex] == INT_MAX) return {};

    vector<vector<string>> ans;
    // dfs 找到所有的路径
    auto dfs = [&](auto func, int index, vector<int>& path) {
      if (index == startIndex) {
        vector<string> wp;
        for (auto p = path.rbegin(); p != path.rend();++p) {
          wp.push_back(wordList[*p]);
        }
        ans.push_back(wp);
        return;
      }
      for (auto& e : edges[index]) {
        if (minDistances[e] == minDistances[index] - 1) {
          path.push_back(e);
          func(func, e, path);
          path.pop_back();
        }
      }
    };
    vector<int> path;
    path.push_back(endIndex);
    dfs(dfs, endIndex, path); 
    return ans;
  }
};