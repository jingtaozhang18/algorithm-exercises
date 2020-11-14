// https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int i,j,k,l,c,r,idx,itvl,size=nums.size();
        vector<int> tmp(nums.begin(), nums.end());
        vector<int> ans(size, 0);
        vector<int> mpo(size); // 记录坐标的变化
        vector<int> mpn(size);
        for(i=0;i<size;++i) mpo[i]=i, mpn[i]=i; // 定位标
        for(itvl=1;itvl<size;itvl*=2){
            for(i=0;i+itvl<size;i+=2*itvl){ // 每段的起点
                l=i,c=i+itvl,r=min(i+itvl*2,size); // 确定边界
                j=l,k=c,idx=l;
                while(j<c&&k<r){
                    if(nums[j]<=nums[k])
                        tmp[idx]=nums[j], ans[mpo[j]]+=k-c, mpn[idx]=mpo[j], idx++, j++;
                    else
                        tmp[idx]=nums[k], mpn[idx]=mpo[k], idx++, k++;
                }
                while(j<c) tmp[idx]=nums[j], ans[mpo[j]]+=r-c, mpn[idx]=mpo[j], idx++, j++;
                while(k<r) tmp[idx]=nums[k], mpn[idx]=mpo[k], idx++, k++;
            }
            for(j=0;j<size;++j) nums[j]=tmp[j], mpo[j]=mpn[j];
        }
        return ans;
    }
};