// https://leetcode-cn.com/contest/weekly-contest-253/problems/remove-stones-to-minimize-the-total/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int x, sum=0;
        priority_queue<int, vector<int>> que;
        for(auto &e:piles){
            que.push(e);
        }
        while(k--){
            x=que.top();
            que.pop();
            if(x%2==1)
                que.push(x/2+1);
            else
                que.push(x/2);
        }
        while(que.size()){
            sum+=que.top();
            que.pop();
        }
        return sum;
    }
};