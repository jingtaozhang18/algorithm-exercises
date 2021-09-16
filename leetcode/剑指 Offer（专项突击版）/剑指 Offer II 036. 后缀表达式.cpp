// https://leetcode-cn.com/problems/8Zf90G/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calc(string& str) {
    int ans = 0;
    bool flag = true;
    for (auto& c : str) {
      if (c == '-')
        flag = false;
      else {
        ans *= 10;
        ans += c - '0';
      }
    }
    return flag ? ans : -ans;
  }
  int evalRPN(vector<string>& tokens) {
    stack<int> sta;
    int x, y;
    for (auto& token : tokens) {
      if (token == "+") {
        y = sta.top();
        sta.pop();
        x = sta.top();
        sta.pop();
        sta.push(x + y);
      } else if (token == "-") {
        y = sta.top();
        sta.pop();
        x = sta.top();
        sta.pop();
        sta.push(x - y);
      } else if (token == "*") {
        y = sta.top();
        sta.pop();
        x = sta.top();
        sta.pop();
        sta.push(x * y);
      } else if (token == "/") {
        y = sta.top();
        sta.pop();
        x = sta.top();
        sta.pop();
        sta.push(x / y);
      } else {
        sta.push(calc(token));
      }
    }
    return sta.top();
  }
};