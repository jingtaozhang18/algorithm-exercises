// https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string &ans, string &s, int& index, int i, bool r, vector<int>& jump){
        // ans[index] 结果字符串
        // s[i] 输入字符串
        // 正序还是反序
        int n=s.size(), j;
        if(r){ // 反序 一定遇到了括号
            for(j=jump[i]-1;j>i;--j){
                if(s[j]==')'){
                    jgo(ans, s, index, jump[j]+1, !r, jump);
                    j=jump[j];
                }else if(s[j]=='('){
                    return;
                }else{
                    ans[index++]=s[j];
                }
            }
        }else{ // 不一定有括号 进入的时候没有括号
            for(;i<n;++i){
                if(s[i]=='('){
                    jgo(ans, s, index, i, !r, jump);
                    i=jump[i];
                }else if(s[i]==')'){
                    return;
                }else{
                    ans[index++]=s[i];
                }
            }
        }
    }
    string reverseParentheses(string s) {
        int i, j, n=s.size(), m=0;
        stack<int> sta;
        vector<int> jump(n, -1); // 左括号的右括号位置； 右括号的左括号位置合并存储
        for(i=0;i<n;++i){
            if(s[i]=='(') sta.push(i);
            else if(s[i]==')') {
                jump[sta.top()]=i;
                jump[i]=sta.top();
                sta.pop();
            }else m++;
        }
        string ans(m, ' ');
        int index=0;
        jgo(ans, s, index, 0, false, jump);
        return ans;
    }
};