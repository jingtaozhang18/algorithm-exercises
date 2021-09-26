// https://leetcode-cn.com/problems/delete-operation-for-two-strings/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<unsigned long long, int> mem;
  int calc(string& word1, string& word2, int i, int j) {
    if (i == word1.size()) return word2.size() - j;
    if (j == word2.size()) return word1.size() - i;
    unsigned long long key =
        ((unsigned long long)i) << 32 | (unsigned long long)j;
    auto p = mem.find(key);
    if (p != mem.end()) return p->second;
    if (word1[i] == word2[j])
      return mem[key] = calc(word1, word2, i + 1, j + 1);
    return mem[key] = min({
               calc(word1, word2, i, j + 1) + 1,
               calc(word1, word2, i + 1, j) + 1,
               calc(word1, word2, i + 1, j + 1) + 2,
           });
  }
  int minDistance(string word1, string word2) {
    return calc(word1, word2, 0, 0);
  }
};