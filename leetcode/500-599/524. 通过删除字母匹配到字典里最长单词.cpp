// https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
#include <bits/stdc++.h>
using namespace std;

struct jcmp {
  const bool operator()(const string& a, const string& b) const {
    if (a.size() == b.size()) {
      return a < b;
    } else {
      return a.size() > b.size();
    }
  }
};

class Solution {
 public:
  bool judge(string& a, string& b) {
    int i = 0, j = 0, m = a.size(), n = b.size();
    while (j < n) {
      if (i == m) return false;
      if (a[i] == b[j])
        ++i, ++j;
      else
        ++i;
    }
    return true;
  }
  string findLongestWord(string s, vector<string>& dictionary) {
    sort(dictionary.begin(), dictionary.end(), jcmp());
    for (auto& str : dictionary) {
      if (judge(s, str)) {
        return str;
      }
    }
    return "";
  }
};