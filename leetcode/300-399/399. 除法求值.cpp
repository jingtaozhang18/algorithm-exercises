// https://leetcode-cn.com/problems/evaluate-division/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> mem;

    double jgo(string a, string b){
      if(mem.find(a)==mem.end()||mem.find(b)==mem.end()) return -1.0;
      if(a==b) return 1.0;
      queue<string> que;
      unordered_map<string, double> st; // 记录路线
      st[a]=1.0;
      que.push(a);
      double x,y;
      while(!que.empty()){
        a=que.front();
        que.pop();
        x=st[a];
        for(auto p:mem[a]){
          if(st.find(p.first)==st.end()){
            y=x*p.second;
            if(p.first==b) return y;
            st[p.first]=y;
            que.push(p.first);
          }
        }
      }
      return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      mem.clear();
      vector<double> ans;
      int i, size=equations.size();
      for(i=0;i<size;++i){
        mem[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
        mem[equations[i][1]].push_back(make_pair(equations[i][0], 1/values[i]));
      }
      for(auto e:queries) ans.push_back(jgo(e[0], e[1]));
      return ans;
    }
};