// https://leetcode-cn.com/problems/valid-parentheses/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(auto e:s){
            if(e=='('||e=='{'||e=='[') sta.push(e);
            else {
                if(e==')'){
                    if(!sta.size()||sta.top()!='(') return false;
                }else if(e==']'){
                    if(!sta.size()||sta.top()!='[') return false;
                }else if(e=='}'){
                    if(!sta.size()||sta.top()!='{') return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};