// https://leetcode-cn.com/problems/simplify-path/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> sta;
    int i = 0, j = 0;
    for (; j <= path.size(); ++j) {
      if (j == path.size() || path[j] == '/') {
        if (j > i) {
          string str = path.substr(i, j - i);
          if (str == "..") {
            if (sta.size())
              sta.pop();
          }
          else if (str == ".");
          else sta.push(str);
        }
        i = j + 1;
      }
    }
    string str = "";
    while (sta.size()) {
      str = "/" + sta.top() + str;
      sta.pop();
    }
    return str.size() ? str : "/";
  }
};