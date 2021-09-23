// https://leetcode-cn.com/problems/fi9suh/
#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
 public:
  map<int, int> mp;
  MyCalendar() {}

  bool book(int start, int end) {
    if (mp.size() == 0) {
      mp[start] = end;
      return true;
    }
    auto p = mp.lower_bound(start);
    if (p != mp.end() && p->first < end) return false;
    auto q = mp.lower_bound(end);
    if (q != mp.begin()) {
      --q;
      if (q->second > start) return false;
    }
    mp[start] = end;
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */