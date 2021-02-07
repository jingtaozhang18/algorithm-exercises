// https://leetcode-cn.com/problems/closest-subsequence-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jgo(vector<int>& arr, int i, int j){
        unordered_set<int> st;
        int flag=0, acc;
        for(flag=0;flag<1<<(j-i+1);++flag){
            acc=0;
            for(int k=i;k<=j;++k){
                if(flag&(1<<(k-i))) acc+=arr[k];
            }
            st.insert(acc);
        }
        return vector<int>(st.begin(), st.end());
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int size=nums.size(), left, right, mid, ans=INT_MAX, tar;
        if(size==1) return min(abs(goal-nums[0]), abs(goal));
        auto a = jgo(nums, 0, (size>>1)-1);
        auto b = jgo(nums, size>>1, size-1);
        sort(b.begin(), b.end());
        size=b.size();
        for(auto e:a){
            left=0, right=size-1, tar=goal-e;
            while(left<=right){
                mid=left+(right-left)/2;
                if(b[mid]>=tar) right=mid-1;
                else left=mid+1; 
            }
            if(0<=left&&left<size) ans=min(ans, abs(e+b[left]-goal));
            left=0, right=size-1;
            while(left<=right){
                mid=left+(right-left)/2;
                if(b[mid]<=tar) left=mid+1;
                else right=mid-1;
            }
            if(0<=right&&right<size) ans=min(ans, abs(e+b[right]-goal));
            if(ans==0) return ans;
        }
        return ans;
    }
};