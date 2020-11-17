// https://leetcode-cn.com/problems/remove-k-digits/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string&ans, char c){
        int size=ans.size();
        if(size==0&&c=='0') return;
        ans+=c;
    }
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0"; // 特殊情况
        int size=num.size(),i;
        string ans="";
        stack<char> sta;
        stack<char> t_sta;
        for(i=0;k&&i<size;++i){
            while(k&&!sta.empty()&&num[i]<sta.top()){
                sta.pop(); // 删除了元素
                k--;
            }
            sta.push(num[i]);
        }
        while(k--) sta.pop();
        while(!sta.empty()){t_sta.push(sta.top()); sta.pop();}
        while(!t_sta.empty()){jgo(ans, t_sta.top()); t_sta.pop();}
        for(;i<size;++i) jgo(ans, num[i]);
        return ans.size()==0?"0":ans;
    }
};