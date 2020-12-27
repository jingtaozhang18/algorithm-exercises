// https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
      int size=s.size(),i,pre=0,pos=0;
      vector<char> arr{'a','e','i','o','u','A','E','I','O','U'};
      set<char> st;
      for(char c:arr) st.insert(c);
      for(i=0;i<size;++i){
        if(st.find(s[i])!=st.end())
          if(i<size/2) pre++;
          else pos++;
      }
      return pre==pos;
    }
};