// https://leetcode-cn.com/problems/valid-parenthesis-string/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_set<unsigned long long> st;
  bool calc(string& s, int i, int acc) {
    unsigned long long key =
        (((unsigned long long)i) << 32) | ((unsigned long long)acc);
    if (st.find(key) != st.end()) return false;
    for (; i < s.size(); ++i) {
      if (s[i] == '(')
        ++acc;
      else if (s[i] == ')') {
        if (acc > 0)
          --acc;
        else
          return false;
      } else {
        key = (((unsigned long long)i) << 32) | ((unsigned long long)acc);
        if (calc(s, i + 1, acc)) return true;
        if (calc(s, i + 1, acc + 1)) return true;
        if (acc) {
          if (calc(s, i + 1, acc - 1)) return true;
        }
        st.insert(key);
        return false;
      }
    }
    return acc == 0;
  }
  bool checkValidString(string s) { return calc(s, 0, 0); }
};
