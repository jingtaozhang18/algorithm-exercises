// https://leetcode-cn.com/problems/xiao-zhang-shua-ti-ji-hua/
#include<bits/stdc++.h>
using namespace std;

// 取消优先级队列，直接记录最大值，减少时间开销
class Solution {
public:
    bool judge(vector<int>& time, int m, int t){ // 每天t小时，是否OK
        int acc=1, cost=0, sum=0; // 第一天, 花费的时间, 算上小杨的时间
        int maxi=0; // 耗时最长的题
        for(int i=0;i<time.size();++i){
            sum+=time[i];
            if(time[i]>time[maxi]) maxi=i;
            cost=sum-time[maxi];
            if(cost>t){
                acc++;
                maxi=i;
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