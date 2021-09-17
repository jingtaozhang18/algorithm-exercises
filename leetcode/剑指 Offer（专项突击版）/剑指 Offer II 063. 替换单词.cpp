// https://leetcode-cn.com/problems/UhWRSj/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* childs[26];
  string str;
  Node() { memset(childs, 0, sizeof childs); }
};

class Solution {
 public:
  Node* root;
  void build(string& str) {
    Node* t = root;
    for (auto& c : str) {
      if (!t->childs[c - 'a']) t->childs[c - 'a'] = new Node();
      t = t->childs[c - 'a'];
    }
    t->str = str;
  }

  string find(string& str, int left, int right) {  // [left, right)
    Node* t = root;
    int i;
    for (i = left; i < right; ++i) {
      if (t->childs[str[i] - 'a']) {
        t = t->childs[str[i] - 'a'];
        if (t->str.size()) {
          return t->str;
        }
      } else {
        return "";
      }
    }
    return "";
  }
  
  string replaceWords(vector<string>& dictionary, string sentence) {
    root = new Node();
    for (auto& str : dictionary) build(str);
    int i, j, k, x;

    for (i = 0, j = 0, k = 0; j <= sentence.size(); ++j) {
      if (j == sentence.size() || sentence[j] == ' ') {
        string t = find(sentence, i, j);
        x = 0;
        if (t.size()) {
          while (x < t.size()) {
            sentence[k++] = t[x++];
          }
        } else {
          while (i < j) {
            sentence[k++] = sentence[i++];
          }
        }
        sentence[k++] = ' ';
        i = j + 1;
      }
    }
    return sentence.substr(0, k - 1);
  }
};