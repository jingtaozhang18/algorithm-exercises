// https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(string&s, string&ans, vector<int>& pos, int &left, int windex, int level){
        // 处理s[left, right]范围内，从ans[windex]开始写入
        int acc=0, i, j, right=pos[left];
        for(i=left;i<=right;++i) acc+=(s[i]!=')'&&s[i]!='(')?1:0;
        int pleft=windex, pright=windex+acc, pans=pright;
        i=left, j=right;
        while(i<=j){
            if(level%2==0){ // 从左到右
                while(i<=j){
                    if(s[i]=='('){ // 进入下一层
                        jgo(s, ans, pos, i, )
                    }
                    ans[pleft++]=s[i];
                    ++i;
                }
            }else{ // 从右到左

            }
        }

    }
    string reverseParentheses(string s) {
        int i, j, n=s.size(), m=0;
        stack<int> sta;
        vector<int> pos(n, -1);
        for(i=0;i<n;++i){
            if(s[i]=='(') sta.push(i);
            else if(s[i]==')') {
                pos[sta.top()]=i;
                sta.pop();
            }
        }
        for(auto &e:s) if(e!='('&&e!=')') ++m;
        string ans(m, ' ');
        if(m==0) return ans;
        if(pos[0]==-1) pos[0]=n-1;
    }
};