// https://leetcode-cn.com/problems/xiao-zhang-shua-ti-ji-hua/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(vector<int>& time, int m, int t){ // 每天t小时，是否OK
        int acc=1, cost=0, sum=0; // 第一天, 花费的时间, 算上小杨的时间
        priority_queue<int, vector<int>, less<int>> que; // 记录这一天中耗时最长的题
        for(int i=0;i<time.size();++i){
            que.push(time[i]);
            sum+=time[i];
            cost=sum-que.top();
            if(cost>t){
                acc++;
                que=priority_queue<int, vector<int>, less<int>>();
                que.push(time[i]);
                sum=time[i];
            }
        }
        if(cost==0) acc--;
        return acc<=m;
    }
    int minTime(vector<int>& time, int m) { // 二分查找的思路， 判断答案是否正确
        int sum=0; for(int c:time) sum+=c;
        int l=0, r=sum, c;
        while(l<=r){
            c=l+(r-l)/2;
            if(judge(time, m, c)) r=c-1;
            else l=c+1;
        }
        return l;
    }
};