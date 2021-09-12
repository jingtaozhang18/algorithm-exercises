// https://leetcode-cn.com/problems/iSwD2y/
#include <bits/stdc++.h>
using namespace std;

struct node {
  node* childs[26];
  node() {
    for (auto& child : childs) child = nullptr;
  }
};

class Solution {
 public:
  node* root = new node();
  int leaf = 0;
  int num = 0;
  void insert(string& word) {
    node* t = root;
    for (int i = word.size() - 1; i >= 0; --i) {
      char c = word[i];
      if (!t->childs[c - 'a']) {
        t->childs[c - 'a'] = new node();
      }
      t = t->childs[c - 'a'];
    }
  }
  void calc(node* t, int deep) {
    num++;
    bool hasChild = false;
    for (auto child : t->childs) {
      if (child) {
        calc(child, deep + 1);
        if (hasChild) num += deep;  // 错误点： 不能复用，重新起一列
        hasChild = true;
      }
    }
    if (!hasChild) ++leaf;
  }
  int minimumLengthEncoding(vector<string>& words) {
    for (auto& word : words) insert(word);
    calc(root, 0);
    return num - 1 + leaf;
  }
};