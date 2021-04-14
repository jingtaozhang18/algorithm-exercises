// https://leetcode-cn.com/problems/re-space-lcci/
#include<bits/stdc++.h>
using namespace std;

// 记忆化动态规划
class Solution {
public:
    int mem[1002];
    int jgo(string& sentence, unordered_set<string>& dictionary, int i){
      if(i==sentence.size()) return 0;
      if(mem[i]!=-1) return mem[i];
      int ans=INT_MAX, x;
      for(int j=i;j<sentence.size();++j){
        x=jgo(sentence, dictionary, j+1);
        if(dictionary.count(sentence.substr(i, j-i+1))) x+=0;
        else x+=(j-i+1);
        ans=min(ans, x);
      }
      return mem[i]=ans;
    }
    int respace(vector<string>& dictionary, string sentence) {
      unordered_set<string> st(dictionary.begin(), dictionary.end());
      for(int i=0;i<sentence.size();++i) mem[i]=-1;
      return jgo(sentence, st, 0);
    }
};