// https://leetcode-cn.com/problems/word-ladder/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    int m = wordList.size(), i, j, target = -1;
    bool edges[m][m], flag;
    auto isN = [](string& a, string& b, int d) -> bool {
      int diff = 0, i;
      for (i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) ++diff;
      return diff == d;
    };
    for (i = 0; i < m; ++i) {
      if (isN(wordList[i], endWord, 0)) target = i;
      for (j = i; j < m; ++j) {
        flag = isN(wordList[i], wordList[j], 1);
        edges[i][j] = edges[j][i] = flag;
      }
    }
    if (target == -1) return 0;
    // bfs search
    queue<int> que;
    vector<int> distance(m, INT_MAX);
    que.push(m - 1);
    distance[m - 1] = 0;
    while (que.size()) {
      i = que.front();
      que.pop();
      if (i == target) return distance[i] + 1;
      for (j = 0; j < m; ++j) {
        if (edges[i][j]) {
          if (distance[i] + 1 < distance[j]) {
            distance[j] = distance[i] + 1;
            que.push(j);
          }
        }
      }
    }
    return 0;
  }
};
