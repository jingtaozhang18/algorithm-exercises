// https://leetcode-cn.com/problems/IY6buf/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_set<int> st;
  int n1, n2, n3;
  int base = 1000;
  bool calc(string& s1, string& s2, string& s3, int i, int j, int k) {
    if (k == n3) return true;
    int key = i * base * base + j * base + k;
    if (st.find(key) != st.end()) return false;
    if (i < n1 && s1[i] == s3[k])
      if (calc(s1, s2, s3, i + 1, j, k + 1)) return true;
    if (j < n2 && s2[j] == s3[k])
      if (calc(s1, s2, s3, i, j + 1, k + 1)) return true;
    st.insert(key);
    return false;
  }

  bool isInterleave(string s1, string s2, string s3) {
    n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3) return false;
    return calc(s1, s2, s3, 0, 0, 0);
  }
};