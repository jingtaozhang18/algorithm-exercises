// https://leetcode-cn.com/problems/is-unique-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
      set<char> st;
      for(char c:astr) {if(st.find(c)!=st.end()) return false; st.insert(c);}
      return true;
    }
};