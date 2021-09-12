// https://leetcode-cn.com/problems/US1pGT/
#include <bits/stdc++.h>
using namespace std;

struct node {
  bool isWord;
  string str;
  node* childs[26];
  node() {
    isWord = false;
    for (auto& child : childs) child = nullptr;
  }
};

class MagicDictionary {
 public:
  node* root;
  unordered_set<string> st;

  MagicDictionary() { root = new node(); }

  void insertword(const string& str) {
    node* t = root;
    for (auto& c : str) {
      if (!t->childs[c - 'a']) {
        t->childs[c - 'a'] = new node();
      }
      t = t->childs[c - 'a'];
    }
    t->isWord = true;
    t->str = str;
  }

  void buildDict(vector<string> dictionary) {
    for (auto& str : dictionary) insertword(str);
    auto isEqual = [](string& a, string& b) -> bool {
      if (a.size() != b.size()) return false;
      int diff = 0;
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++diff;
        if (diff > 1) return false;
      }
      return true;
    };
    int i, j, n = dictionary.size();
    for (i = 0; i < n; ++i) {
      for (j = i + 1; j < n; ++j) {
        if (isEqual(dictionary[i], dictionary[j])) {
          st.insert(dictionary[i]);
          st.insert(dictionary[j]);
        }
      }
    }
  }

  bool calc(string& word, int i, node* t) {
    for (++i; i < word.size(); ++i) {
      if (t->childs[word[i] - 'a']) {
        t = t->childs[word[i] - 'a'];
      } else {
        return false;
      }
    }
    return t->isWord;
  }

  bool search(string searchWord) {
    node* t = root;
    int i = 0;
    for (char& c : searchWord) {
      if (t->childs[c - 'a']) {
        for (auto& child : t->childs) {
          if (child && child != t->childs[c - 'a'] &&
              calc(searchWord, i, child))
            return true;
        }
        t = t->childs[c - 'a'];
      } else {
        for (auto child : t->childs) {
          if (child && calc(searchWord, i, child)) return true;
        }
        return false;
      }
      ++i;
    }
    return t->isWord && st.find(t->str) != st.end();
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
