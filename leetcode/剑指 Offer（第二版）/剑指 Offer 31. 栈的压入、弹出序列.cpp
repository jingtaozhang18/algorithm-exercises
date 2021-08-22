// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;
        int i=0,j=0,len=pushed.size();
        while(j<len){
            if(!sta.empty()&&sta.top()==popped[j]){
                sta.pop();
                j++;
            }else if(i==len) return false;
            else sta.push(pushed[i++]);
        }
        return true;
    }
};