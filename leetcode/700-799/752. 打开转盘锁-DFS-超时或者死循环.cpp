// https://leetcode-cn.com/problems/open-the-lock/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    map<string, int> mem; // 开始探索的集合
    char jround(char c, int i){ return '0'+(((c-'0')+i+20)%10); }
    bool jdead(string now, vector<string>& deadends){
        for(auto s:deadends) if(s==now) return true;
        return false;
    }
    void jgo(string& now, int times, vector<string>&deadends, string& target){
        // cout<<now<<" "<<times<<endl;
        int i,j;
        if(jdead(now, deadends)) return; // 不满足条件
        if(times>=ans) return; // 没有意义了
        if(now==target) {ans=min(ans, times);} // 收集答案
        if(mem.find(now)==mem.end()) mem[now]=times;
        else {
            if(mem[now]<=times) return; // 没有必要了,当前状态已经有最优解了
            else mem[now]=times;
        }
        for(i=0;i<4;++i){
            now[i]=jround(now[i], 1);
            if(mem[now]==times) jgo(now, times+1, deadends, target);
            now[i]=jround(now[i], -2);
            if(mem[now]==times) jgo(now, times+1, deadends, target);
            now[i]=jround(now[i], 1);
        }
    }
    int openLock(vector<string>& deadends, string target) {
        ans=INT_MAX;
        string now="0000";
        mem.clear();
        jgo(now, 0, deadends, target);
        return ans;
    }
};