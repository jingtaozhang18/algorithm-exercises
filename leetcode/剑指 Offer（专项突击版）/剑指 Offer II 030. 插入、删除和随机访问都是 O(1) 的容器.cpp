// https://leetcode-cn.com/problems/FortPu/
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
 public:
  unordered_set<int> st;
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (st.find(val) == st.end()) {
      st.insert(val);
      return true;
    }
    return false;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (st.find(val) != st.end()) {
      st.erase(val);
      return true;
    }
    return false;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int x = rand() % st.size();
    auto p = st.begin();
    while (x--) ++p;
    return *p;
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */