// https://leetcode-cn.com/problems/word-search-ii/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  string word;
  int count = 0;
  Node* childs[26];
  Node() : count(0) {
    for (auto& e : childs) e = nullptr;
  };
};

class Solution {
 public:
  Node* root;
  int m, n;
  vector<string> ans;
  int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

  void build(string& str) {
    Node* t = root;
    for (char& c : str) {
      ++t->count;
      if (!t->childs[c - 'a']) t->childs[c - 'a'] = new Node();
      t = t->childs[c - 'a'];
    }
    ++t->count;
    t->word = str;
  }

  int jgao(vector<vector<char>>& arr, int a, int b,
           vector<vector<short>>& color, Node* t) {
    int i, x, y, del = 0;
    if (t->count == 0 || !t->childs[arr[a][b] - 'a']) return 0;
    t = t->childs[arr[a][b] - 'a'];
    if (t->word.size()) {
      ans.push_back(t->word);
      t->word = "";
      ++del;
    }
    color[a][b] = 1;
    for (i = 0; i < 4; ++i) {
      x = a + dir[i][0];
      y = b + dir[i][1];
      if (x >= 0 && x < m && y >= 0 && y < n && color[x][y] == 0) {
        del += jgao(arr, x, y, color, t);
      }
    }
    color[a][b] = 0;
    t->count -= del;
    return del;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new Node();
    int i, j;
    for (auto& word : words) build(word);
    m = board.size(), n = board[0].size();
    vector<vector<short>> color(m, vector<short>(n, 0));
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        jgao(board, i, j, color, root);
      }
    }
    return ans;
  }
};
