// https://leetcode-cn.com/problems/maximal-rectangle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), i, j, ans=0, t;
        if(n==0) return 0;
        vector<int> arr(n, 0);
        vector<int> dp_l(n, 0);
        vector<int> dp_r(n, 0);
        stack<int> sta; // 存放下标
        for(i=0;i<m;++i){
            for(j=0;j<n;++j) {
                if(matrix[i][j]=='1') arr[j]++; 
                else arr[j]=0; 
                dp_l[j]=-1, dp_r[j]=n;
            }
            while(!sta.empty()) sta.pop();
            for(j=0;j<n;++j){
                // 正确思路:当前高度给比之前更高的列赋右边界的值
                //         在去除所有比当前列大的列之后，如果剩下就是当前列的左边界
                while(!sta.empty()&&arr[sta.top()]>arr[j]){ // 底小顶大
                    dp_r[sta.top()]=j; sta.pop();
                }
                if(!sta.empty()) dp_l[j]=sta.top();
                // 错误点 如下，while中重复给dp_l[j]赋值，必定出错
                // while(!sta.empty()&&arr[sta.top()]<arr[j]){ // 底大顶小
                //     dp_l[j]=sta.top(); sta.pop();
                // }
                // if(!sta.empty()&&arr[sta.top()]>arr[j]) dp_r[sta.top()]=j;
                sta.push(j);
            }
            for(j=0;j<n;++j){
                t=arr[j]*(dp_r[j]-dp_l[j]-1);
                ans=max(ans, t);
            }
        }
        return ans;
    }
};