// https://leetcode-cn.com/problems/count-of-range-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<long long>&nums, int lower, int upper, int left, int right){ // [left, right]
        int ans=0,tans=0,c,i,j,k,a,b; long long t;
        if(left==right) return 0;
        c=(left+right+1)>>1;
        tans+=jgo(nums, lower, upper, left, c-1);
        tans+=jgo(nums, lower, upper, c, right);
        vector<long long> tnums(right-left+1);
        // 找到左右标界
        for(a=c;a<=right&&nums[a]-nums[left]<lower;++a);  // 闭区间
        for(b=a;b<=right&&nums[b]-nums[left]<=upper;++b); // 开区间
        for(i=left,j=c,k=0;i<c&&j<=right;){
            if(nums[i]<nums[j]) {
                tnums[k++]=nums[i++], ans+=(b-a);
                for(;a<=right&&nums[a]-nums[i]<lower;++a);  // 闭区间
                for(;b<=right&&nums[b]-nums[i]<=upper;++b); // 开区间
            }else tnums[k++]=nums[j++];
        }
        while(i<c) {
            tnums[k++]=nums[i++], ans+=(b-a);
            for(;a<=right&&nums[a]-nums[i]<lower;++a);  // 闭区间
            for(;b<=right&&nums[b]-nums[i]<=upper;++b); // 开区间
        }
        while(j<=right) tnums[k++]=nums[j++];
        for(i=left;i<=right;++i) nums[i]=tnums[i-left];
        // cout<<left<<" "<<right<<" :"<<ans<<endl;
        return ans+tans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return false;
        vector<long long> tnums(nums.size()+1);
        int i;long long t;
        tnums[0]=0;
        for(i=0,t=0;i<nums.size();++i) t+=nums[i], tnums[i+1]=t;
        // for(int i=0;i<tnums.size();++i)cout<<tnums[i]<<" ";
        // cout<<endl;
        return jgo(tnums, lower, upper, 0, tnums.size()-1);
    }
};