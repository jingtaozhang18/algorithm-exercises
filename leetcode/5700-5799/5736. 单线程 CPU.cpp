// https://leetcode-cn.com/contest/weekly-contest-237/problems/single-threaded-cpu/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int start;
    int need;
    int index;
    node(int s, int n, int i):start(s),need(n),index(i){};
    bool operator<(const node& other) const{
        if(need==other.need) return index>other.index;
        return need>other.need;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int i, n=tasks.size();
        long long t;
        
        vector<int> ans;
        priority_queue<node> que;
        
        for(i=0;i<n;++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

        t=tasks[0][0], i=0;
        while(i<n||que.size()){
            while(i<n&&tasks[i][0]<=t) {que.push(node(tasks[i][0], tasks[i][1], tasks[i][2])); ++i;}
            if(que.size()){
                node nd=que.top(); que.pop();
                ans.push_back(nd.index);
                t=t+nd.need;
            }else{
                t=tasks[i][0];   
            }
        }
        return ans;
    }
};