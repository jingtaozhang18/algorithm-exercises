// https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> sta;
        for(auto e:S){
            if(sta.size()&&sta.top()==e) sta.pop();
            else sta.push(e);
        }
        string ans(sta.size(), ' ');
        for(int i=sta.size()-1;i>=0;--i){
            ans[i]=sta.top();
            sta.pop();
        }
        return ans;
    }
};