// https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/
#include<bits/stdc++.h>
using namespace std;

struct node {
  node* childs[26];
  bool isWord;
  node() :isWord(false) {
    memset(childs, 0, sizeof childs);
  }
};
class WordDictionary {
public:
  node* root;
  WordDictionary() {
    root = new node();
  }

  void addWord(string word) {
    node* t = root;
    for (auto& c : word) {
      if (!t->childs[c - 'a']) t->childs[c - 'a'] = new node();
      t = t->childs[c - 'a'];
    }
    t->isWord = true;
  }

  bool helper_search(string& word, node* t, int i) {
    for (;i < word.size();++i) {
      if (word[i] == '.') {
        for (auto& child : t->childs) {
          if (child) {
            if (helper_search(word, child, i + 1)) return true;
          }
        }
        return false;
      }
      else {
        if (t->childs[word[i] - 'a']) {
          t = t->childs[word[i] - 'a'];
        }
        else {
          return false;
        }
      }
    }
    return t->isWord;
  }
  bool search(string word) {
    return helper_search(word, root, 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */