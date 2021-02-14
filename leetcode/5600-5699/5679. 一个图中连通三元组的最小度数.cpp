// https://leetcode-cn.com/contest/weekly-contest-228/problems/minimum-degree-of-a-connected-trio-in-a-graph/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> arr(n+1, vector<bool>(n+1, false));
        unordered_map<int, int> degree;
        int ans=INT_MAX, i, j, k;
        for(i=0;i<edges.size();++i){
            j=edges[i][0], k=edges[i][1];
            arr[j][k]=arr[k][j]=true;
            degree[j]++, degree[k]++;
        }
        
        for(i=1;i<=n;++i){
            for(j=i+1;j<=n;++j){
                if(!arr[i][j]) continue;
                for(k=j+1;k<=n;++k){
                    if(!arr[i][k]) continue;
                    if(arr[j][k]) ans=min(ans, degree[i]+degree[j]+degree[k]-6);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};