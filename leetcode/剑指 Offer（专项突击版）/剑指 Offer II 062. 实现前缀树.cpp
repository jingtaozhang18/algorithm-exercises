// https://leetcode-cn.com/problems/QC3q1f/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  bool isWord;
  Node* childs[26];
  Node() : isWord(false) { memset(childs, 0, sizeof childs); }
};

class Trie {
 public:
  Node* root;
  Trie() { root = new Node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node* t = root;
    for (auto& c : word) {
      if (!t->childs[c - 'a']) t->childs[c - 'a'] = new Node();
      t = t->childs[c - 'a'];
    }
    t->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node* t = root;
    for (auto& c : word) {
      if (!t->childs[c - 'a']) return false;
      t = t->childs[c - 'a'];
    }
    return t->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Node* t = root;
    for (auto& c : prefix) {
      if (!t->childs[c - 'a']) return false;
      t = t->childs[c - 'a'];
    }
    return t;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */