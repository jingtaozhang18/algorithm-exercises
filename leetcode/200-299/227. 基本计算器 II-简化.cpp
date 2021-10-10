// https://leetcode-cn.com/problems/basic-calculator-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isdigit(char c) { return c >= '0' && c <= '9'; }
  int calculate(string s) {
    char sign = '+'; int num = 0, a;
    stack<int> sta;
    int index = 0;
    for (char c : s) {
      if (isdigit(c)) num = num * 10 + (c - '0');
      if ((!isdigit(c) && c != ' ') || index == s.size() - 1) {
        if (sign == '+') sta.push(num);
        else if (sign == '-') sta.push(-num);
        else if (sign == '*' || sign == '/') {
          a = sta.top(); sta.pop();
          if (sign == '*') sta.push(a * num);
          else sta.push(a / num);
        }
        sign = c, num = 0;
      }
      ++index;
    }
    num = 0;
    do {
      num += sta.top();
      sta.pop();
    } while (!sta.empty());
    return num;
  }
};

// 复习，自己的思路破灭了， 下面的思路和上面的思路一样
class Solution_fx {
public:
  int readInt(string& s, int& i) {
    int ans = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') ans *= 10, ans += s[i] - '0', ++i;
    return ans;
  }
  inline void ignore(string& s, int& i) {
    while (i < s.size() && s[i] == ' ') ++i;
  }
  int calculate(string s) {
    stack<int> num; char op = '+';
    int i;
    for (i = 0;i < s.size();) {
      ignore(s, i);
      int a = readInt(s, i);
      ignore(s, i);
      if (op == '+') num.push(a);
      else if (op == '-') num.push(-a);
      else if (op == '*') {
        int b = num.top(); num.pop();
        num.push(a * b);
      }
      else if (op == '/') {
        int b = num.top(); num.pop();
        num.push(b / a);
      }
      if (i < s.size()) op = s[i++];
    }
    int acc = 0;
    while (num.size()) { acc += num.top(); num.pop(); }
    return acc;
  }
};