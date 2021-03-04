// https://leetcode-cn.com/problems/russian-doll-envelopes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        auto cmp = [](vector<int> &a, vector<int> &b){ // 要来判断， 被判断
            return a[1]>b[1];
        };
        int i, n=envelopes.size(), ans=0;
        vector<int> dp(n); // 最长公共子序列 贪心算法, 只针对第二列
        for(i=0;i<n;++i){
            int left=0, right=ans-1, mid;
            while(left<=right){
                mid=left+((right-left)>>1);
                bool flag = cmp(envelopes[i], envelopes[dp[mid]]);
                if(flag){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            if(left==ans) dp[ans++]=i;
            else dp[left]=i;
        }
        return ans;
    }
};