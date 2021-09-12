// https://leetcode-cn.com/problems/z1R5dt/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int num;
  Node* childs[26];
  Node() {
    num = 0;
    for (auto& child : childs) child = nullptr;
  }
};

class MapSum {
 public:
  Node* root;
  unordered_map<string, int> mp;
  MapSum() { root = new Node(); }

  void insert(string key, int val) {
    Node* t = root;
    int x = val - mp[key];  // 变化值
    mp[key] = val;
    for (char& c : key) {
      if (!t->childs[c - 'a']) {
        t->childs[c - 'a'] = new Node();
      }
      t->num += x;
      t = t->childs[c - 'a'];
    }
    t->num += x;
  }

  int sum(string prefix) {
    Node* t = root;
    for (auto& c : prefix) {
      if (t->childs[c - 'a']) {
        t = t->childs[c - 'a'];
      } else {
        return 0;
      }
    }
    return t->num;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */