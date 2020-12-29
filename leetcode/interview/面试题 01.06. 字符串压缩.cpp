// https://leetcode-cn.com/problems/compress-string-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressString(string S) {
      int size=S.size(),i,cfn=0,cfk=1;
      for(i=1;i<size;++i) if(S[i]==S[i-1]) cfn++; else cfk++;
      if(cfn<=cfk) return S;
      cfn=1;
      char t=S[0];
      string ans="";
      for(i=1;i<size;++i)
      {
        if(S[i]==S[i-1]) cfn++;
        else{
          ans+=t,ans+=to_string(cfn);
          cfn=1, t=S[i];
        }
      }
      ans+=t,ans+=to_string(cfn);
      return ans;
    }
};