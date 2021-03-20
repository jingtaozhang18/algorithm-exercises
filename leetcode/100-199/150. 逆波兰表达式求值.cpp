// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      int n=tokens.size(), i, j, val, x, y;
      stack<int> st;
      for(i=0;i<n;++i){
        if(tokens[i].size()>1||(tokens[i][0]>='0'&&tokens[i][0]<='9')){
          val=0;
          for(j=0;j<tokens[i].size();++j){
            if(j==0&&tokens[i][0]=='-') continue;
            val*=10;
            val+=tokens[i][j]-'0';
          }
          if(tokens[i][0]=='-') val = -val;
          st.push(val);
        }else{
          y=st.top(); st.pop();
          x=st.top(); st.pop();
          if(tokens[i][0]=='+'){
            st.push(x+y);
          }else if(tokens[i][0]=='-'){
            st.push(x-y);
          }else if(tokens[i][0]=='*'){
            st.push(x*y);
          }else if(tokens[i][0]=='/'){
            st.push(x/y);
          }
        }
      }
      return st.top();
    }
};