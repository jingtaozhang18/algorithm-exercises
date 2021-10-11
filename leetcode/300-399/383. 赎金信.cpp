// https://leetcode-cn.com/problems/ransom-note/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mem;
    int diff = 0;
    for (auto& c : ransomNote) {
      ++mem[c];
      ++diff;
    }
    for (auto& c : magazine) {
      --mem[c];
      if (mem[c] >= 0) --diff;
    }
    return diff == 0;
  }
};