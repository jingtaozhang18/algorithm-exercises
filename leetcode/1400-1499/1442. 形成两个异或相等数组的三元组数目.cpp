// https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i, j, k, ans=0, n=arr.size();
        vector<int> acc(n+1);
        unordered_map<int, vector<int>> mp;
        for(i=0;i<n;++i) acc[i+1]=acc[i]^arr[i], mp[acc[i+1]].push_back(i);
        for(i=0;i<n-1;++i){
            if(mp.find(acc[i])!=mp.end()){
                for(k=0;k<mp[acc[i]].size()&&mp[acc[i]][k]<i;++k);
                for(;k<mp[acc[i]].size();++k){
                    ans+=(mp[acc[i]][k]-i);
                }
            }
        }
        return ans;
    }
};

// 不是用存储过程，效率没有明显的提升
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i, j, ans=0, n=arr.size();
        vector<int> acc(n+1);
        for(i=0;i<n;++i) acc[i+1]=acc[i]^arr[i];
        for(i=0;i<n-1;++i){
            for(j=i+1;j<=n;++j){
                if(acc[j]==acc[i]) ans+=(j-i-1);
            }
        }
        return ans;
    }
};

// 一次循环，速度击败100%
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i, j, acc=0, ans=0, n=arr.size();
        unordered_map<int, int> index_sum;
        unordered_map<int, int> count;
        index_sum[0]=0;
        count[0]++;
        for(i=0;i<n;++i) {
            acc^=arr[i];
            if(count.count(acc)){
                ans+=count[acc]*i-index_sum[acc];
            }
            index_sum[acc]+=(i+1);
            count[acc]++;
        }
        return ans;
    }
};