// https://leetcode-cn.com/problems/word-break/
#include <bits/stdc++.h>
using namespace std;

struct node {
  node* next[200];
  bool flag;
  node() : flag(false) {
    for (int i = 0; i < 200; ++i) {
      next[i] = nullptr;
    }
  }
};

void build(node* root, string& s) {
  for (char& c : s) {
    if (!root->next[c]) {
      root->next[c] = new node();
    }
    root = root->next[c];
  }
  root->flag = true;
}

class Solution {
 public:
  node* root;
  
  bool jcalc(string& s, int i) {
    node* t = root;
    for (; i < s.size(); ++i) {
      char c = s[i];
      if (t->next[c]) {
        t = t->next[c];
        if (t->flag) {
          if (jcalc(s, i + 1)) {
            return true;
          }
        }
      } else {
        return false;
      }
    }
    return t->flag;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    root = new node();
    for (auto& s : wordDict) build(root, s);
    return jcalc(s, 0);
  }
};