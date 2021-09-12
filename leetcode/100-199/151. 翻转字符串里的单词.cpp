// https://leetcode-cn.com/problems/reverse-words-in-a-string/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int i, j = 0, n = s.size();
    bool isw = false;  // is true, can have a space, else non
    for (i = 0; i < n; ++i) {
      if (s[i] != ' ') {
        isw = true;
        s[j++] = s[i];
      } else {
        if (isw) {
          isw = false;
          s[j++] = s[i];
        }
      }
    }
    // 去掉最后一个空格
    --j;
    if (s[j] == ' ') --j;
    // 剩余字符数量
    n = j + 1;
    auto revs = [&s](int i, int j) -> void {
      while (i < j) {
        swap(s[i++], s[j--]);
      }
    };
    revs(0, n - 1);
    for (i = 0, j = 0; i <= n; ++i) {
      if (i == n || s[i] == ' ') {
        revs(j, i - 1);
        j = i + 1;
      }
    }
    return s.substr(0, n);
  }
};