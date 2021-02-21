// https://leetcode-cn.com/contest/biweekly-contest-46/problems/tree-of-coprimes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int x, int y){
        if(x%y){
            return gcd(y, x%y);
        }
        return y;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int size=nums.size(), i, n=edges.size(), f, x,y;
        vector<int> father(size, -1);
        vector<vector<int>> a(size); // 邻接矩阵
        vector<int> ans(size, -1);
        for(i=0;i<n;++i) {
            x=edges[i][1], y=edges[i][0];
            a[x].push_back(y);
            a[y].push_back(x);
        }
        queue<pair<int, int>> que;
        que.push(make_pair(0, -1));
        while(que.size()){
            x=que.front().first, y=que.front().second;
            que.pop();
            for(auto e:a[x]){
                if(y==e) continue;
                father[e]=x;
                que.push(make_pair(e,x));
            }
        }
            
        for(i=0;i<size;++i){
            f=father[i];
            while(f!=-1){
                // cout<<i<<" "<<f<<endl;
                if(gcd(nums[f], nums[i])==1) {
                    ans[i]=f;
                    break;
                }
                f=father[f];
            }
        }
        return ans;
    }
};