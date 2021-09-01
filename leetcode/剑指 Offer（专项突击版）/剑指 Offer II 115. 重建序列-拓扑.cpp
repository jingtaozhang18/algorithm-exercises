// https://leetcode-cn.com/problems/ur2n8P/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
    if (seqs.size() == 0) return false;
    vector<int> degree(org.size() + 1, 0);
    unordered_map<int, vector<int>> aff;
    int i, x;
    for (auto &seq : seqs) {
      for (auto e : seq) {
        if (e > org.size()) return false;
      }
      for (i = 1; i < seq.size(); ++i) {
        degree[seq[i]]++;
        aff[seq[i - 1]].push_back(seq[i]);
      }
    }
    x = 0;
    for (i = 1; i <= org.size(); ++i) {
      if (degree[i] == 0) ++x;
    }
    if (x != 1) return false;
    for (auto &e : org) {
      if (degree[e] != 0) return false;
      x = 0;
      for (auto &s : aff[e]) {
        if (--degree[s] == 0) ++x;
      }
      if (x > 1) return false;
    }
    return true;
  }
};
