// https://leetcode-cn.com/problems/group-anagrams-lcci/
#include<bits/stdc++.h>
using namespace std;

struct node{
  string s;
  int index;
  node(string ss, int i):s(ss),index(i){sort(s.begin(), s.end());} // 错误点 区分参数和自身的变量
  bool operator<(const node& other)const{
    return s<other.s;
  }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<node> fs;
        vector<vector<string>> ans;
        vector<string> t;
        int i;
        string sample;
        for(i=0;i<strs.size();++i) fs.push_back(node(strs[i], i));
        sort(fs.begin(), fs.end());
        sample="";
        for(i=0;i<fs.size();++i)
        {
          if(fs[i].s!=sample)
          {
            sample=fs[i].s;
            if(t.size()) ans.push_back(t);
            t=vector<string>();
          }
          t.push_back(strs[fs[i].index]);
        }
        if(t.size()) ans.push_back(t);
        return ans;
    }
};