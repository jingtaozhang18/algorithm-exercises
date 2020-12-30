// https://leetcode-cn.com/problems/string-to-url-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
      int sp=0, i, j;
      for(i=0;i<length;++i) if(S[i]==' ') sp++;
      i=length-1,j=length+2*sp-1;
      for(;i>=0;--i)
      {
        if(S[i]==' ') S[j--]='0',S[j--]='2',S[j--]='%';
        else S[j--]=S[i];
      }
      return S.substr(0, length+2*sp);
    }
};