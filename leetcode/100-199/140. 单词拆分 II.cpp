// https://leetcode-cn.com/problems/word-break-ii/
#include<bits/stdc++.h>
using namespace std;

struct node {
  node* childs[26];
  bool isWord;
  node() :isWord(false) {
    memset(childs, 0, sizeof childs);
  }
  node* insert(char c) {
    if (childs[c - 'a'] == nullptr)
      childs[c - 'a'] = new node();
    return childs[c - 'a'];
  }
};
class Solution {
public:
  node* root;
  void build(string& str) {
    node* t = root;
    for (char& c : str) {
      t = t->insert(c);
    }
    t->isWord = true;
  }
  void jgo(vector<string>& ans, string& s, int i, vector<int>& path) {
    if (i == s.size()) {
      int i = 0;
      string sa;
      for (auto& j : path) {
        if (i == 0) {
          sa += s.substr(i, j - i);
        }
        else {
          sa += " " + s.substr(i, j - i);
        }
        i = j;
      }
      ans.push_back(sa);
      return;
    }
    node* t = root;
    for (;i < s.size();++i) {
      t = t->childs[s[i] - 'a'];
      if (t) {
        if (t->isWord) {
          path.push_back(i + 1);
          jgo(ans, s, i + 1, path);
          path.pop_back();
        }
        else {
          continue;
        }
      }
      else {
        return;
      }
    }
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    root = new node();
    for (string& str : wordDict) build(str);
    vector<string> ans;
    vector<int> path;
    jgo(ans, s, 0, path);
    return ans;
  }
};
