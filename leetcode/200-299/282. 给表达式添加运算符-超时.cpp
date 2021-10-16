// https://leetcode-cn.com/problems/expression-add-operators/
#include<bits/stdc++.h>
using namespace std;

struct node {
  char op;
  long long num;
  bool isOp;
  node(char op) :op(op), isOp(true) {};
  node(long long num) :num(num), isOp(false) {};
};

class Solution {
public:
  vector<string> ans;
  void calc(string& num, int index, int target, bool isStart, vector<node>& path) {
    if (index == num.size()) {
      stack<long long> sta;
      char c = '+';
      for (auto& e : path) {
        if (e.isOp) c = e.op;
        else {
          if (c == '+') sta.push(e.num);
          else if (c == '-') sta.push(-e.num);
          else {
            long long pre = sta.top();
            sta.pop();
            sta.push(pre * e.num);
          }
        }
      }
      long long res = 0;
      while (sta.size()) { res += sta.top(); sta.pop(); }
      if (res == target && path.size()) {
        string str;
        for (auto& e : path) {
          if (e.isOp) {
            str += e.op;
          }
          else {
            str += to_string(e.num);
          }
        }
        ans.push_back(str);
      }
      return;
    }
    long long x = 0;
    int i;
    for (i = index;i < num.size() && (i == index || num[index] != '0');++i) {
      x *= 10;
      x += num[i] - '0';
      if (isStart) {
        path.push_back(node(x));
        calc(num, i + 1, target, false, path);
        path.pop_back();
      }
      else {
        path.push_back(node('+'));
        path.push_back(node(x));
        calc(num, i + 1, target, false, path);
        path.pop_back();
        path.pop_back();

        path.push_back(node('-'));
        path.push_back(node(x));
        calc(num, i + 1, target, false, path);
        path.pop_back();
        path.pop_back();

        path.push_back(node('*'));
        path.push_back(node(x));
        calc(num, i + 1, target, false, path);
        path.pop_back();
        path.pop_back();
      }
    }
  }
  vector<string> addOperators(string num, int target) {
    vector<node> path;
    ans.clear();
    calc(num, 0, target, true, path);
    return ans;
  }
};