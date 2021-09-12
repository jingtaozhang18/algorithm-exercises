// https://leetcode-cn.com/problems/OrIXps/
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
 public:
  list<int> lt;
  unordered_map<int, list<int>::iterator> mp_key2lt;  // key对应的list节点
  unordered_map<int, int> mp_lt2key;
  unordered_map<int, int> mem;  // key2value
  int capacity;
  int index = 0;

  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (mem.find(key) == mem.end()) {
      return -1;
    } else {
      int value = mem[key];
      int kindex = *mp_key2lt[key];
      lt.erase(mp_key2lt[key]);
      lt.push_front(kindex);
      mp_key2lt[key] = lt.begin();
      return value;
    }
  }

  void put(int key, int value) {
    if (mem.find(key) != mem.end()) {
      mem[key] = value;
      get(key);
    } else {
      if (lt.size() == capacity) {  // 删除
        int remove_key = mp_lt2key[*lt.rbegin()];
        mem.erase(remove_key);
        mp_key2lt.erase(remove_key);
        mp_lt2key.erase(*lt.rbegin());
        lt.pop_back();
      }
      lt.push_front(index);
      mp_key2lt[key] = lt.begin();
      mp_lt2key[index] = key;
      mem[key] = value;
      ++index;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */