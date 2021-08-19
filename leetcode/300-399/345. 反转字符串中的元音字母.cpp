// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    inline bool iss(char c){
      if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
      if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
      return false;
    }
    string reverseVowels(string s) {
      int i=0, j=s.size();
      while(i<j){
        while(i<j&&!iss(s[i])) ++i;
        while(i<j&&!iss(s[j])) --j;
        if(i<j) swap(s[i], s[j]);
        ++i, --j;
      }
      return s;
    }
};
