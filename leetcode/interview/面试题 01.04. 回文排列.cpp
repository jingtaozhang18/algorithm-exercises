// https://leetcode-cn.com/problems/palindrome-permutation-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
      set<char> st;
      for(char c:s)
      {
        if(st.find(c)==st.end()) st.insert(c);
        else st.erase(st.find(c));
      }
      return st.size()<=1;
    }
};