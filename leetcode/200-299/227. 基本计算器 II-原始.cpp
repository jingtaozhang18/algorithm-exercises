// https://leetcode-cn.com/problems/basic-calculator-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int readNum(string&s, int& index){
        int ans=0;
        // 错误点，无法读取最小负数
        for(;index<s.size()&&s[index]>='0'&&s[index]<='9';++index) ans=ans*10+(s[index]-'0'); // 错误点，减法先行，防止溢出
        return ans;
    }
    void jgo(stack<int>& nums, stack<char>& op, bool cc){ // 将之前的积压都算出来
        int a,b;
        while(!op.empty()&&(!cc||(cc&&(op.top()=='*'||op.top()=='/')))){
            a=nums.top(); nums.pop();
            b=nums.top(); nums.pop();
            if(op.top()=='+') nums.push(a+b);
            else if(op.top()=='-') nums.push(b-a);
            else if(op.top()=='*') nums.push(b*a);
            else nums.push(b/a);
            op.pop();
        }
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> op;
        int i;
        for(i=0;i<s.size();){
            if(s[i]==' ') {++i; continue;}
            else if(s[i]=='*'||s[i]=='/') {
                jgo(nums, op, true);
                op.push(s[i]); 
                ++i;
            }else if(s[i]=='+'||s[i]=='-') {
                jgo(nums, op, false); // 乘除之间也有计算顺序
                op.push(s[i]);
                ++i;
            }else{
                nums.push(readNum(s, i));
            }
        }
        jgo(nums, op, false);
        return nums.top();
    }
};