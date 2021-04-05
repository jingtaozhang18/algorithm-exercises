// https://leetcode-cn.com/problems/minimum-absolute-sum-difference/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> st(nums1.begin(), nums1.end());
        int i, n=nums2.size(), a, maxdiff=0, sumdiff=0, mod=1e9+7; // 能减少的最大值
        for(i=0;i<n;++i){
            a=nums2[i];
            auto p=st.lower_bound(a);
            if(p==st.end()) maxdiff=max(maxdiff, abs(nums1[i]-nums2[i])-abs(a-*(--p)));
            else if(p==st.begin()) maxdiff=max(maxdiff, abs(nums1[i]-nums2[i])-abs(a-*(p)));
            else{
                maxdiff=max(maxdiff, 
                                max(abs(nums1[i]-nums2[i])-abs(a-*(p)),
                                    abs(nums1[i]-nums2[i])-abs(a-*(--p)))
                                );
            }
            sumdiff+=abs(nums2[i]-nums1[i]);
            sumdiff%=mod;
        }
        sumdiff-=maxdiff;
        sumdiff%=mod;
        return sumdiff;
    }
};