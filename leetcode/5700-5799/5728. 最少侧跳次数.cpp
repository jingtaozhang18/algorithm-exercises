// https://leetcode-cn.com/contest/weekly-contest-236/problems/minimum-sideway-jumps/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        queue<int> que[4];
        int i, n=obstacles.size(), ans=0, cur=2, x, a,b,k;
        for(i=0;i<n;++i){
            if(obstacles[i]==0) continue;
            que[obstacles[i]].push(i);
        }
        que[1].push(n+1);
        que[2].push(n+1);
        que[3].push(n+1);
        i=que[cur].front()-1;
        for(k=1;k<=3;++k) while(que[k].front()<i) que[k].pop();
        while(i<n){
            for(k=1;k<=3;++k) if(que[k].front()>que[cur].front()) cur=k;
            i=que[cur].front()-1;
            for(k=1;k<=3;++k) while(que[k].front()<i) que[k].pop();
            ans++;
        }
        return ans;
    }
};