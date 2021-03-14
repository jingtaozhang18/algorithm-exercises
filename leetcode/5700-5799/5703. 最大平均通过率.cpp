// https://leetcode-cn.com/contest/weekly-contest-232/problems/maximum-average-pass-ratio/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int p, t;
    node(int p, int t):p(p),t(t){}
    double profile()const{
        return double(p+1)/(t+1) - double(p)/t;
    }
    bool operator<(const node& other)const{
        return profile()<other.profile();
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<node, vector<node>, less<node>> que;
        for(auto e:classes){
            que.push(node(e[0], e[1]));
        }
        while(extraStudents--){
            node t=que.top();
            que.pop();
            t.p++, t.t++;
            que.push(t);
        }
        double val=0, n=classes.size();
        while(que.size()){
            node t=que.top(); que.pop();
            val+=double(t.p)/t.t;
        }
        return val/n;
    }
};