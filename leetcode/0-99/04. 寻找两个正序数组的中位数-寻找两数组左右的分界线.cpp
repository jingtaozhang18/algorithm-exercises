// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size()){
            if(nums2.size()%2) return nums2[nums2.size()/2];
            else return ((double)nums2[nums2.size()/2]+(double)nums2[nums2.size()/2-1])/2;
        }
        if(!nums2.size()){
            if(nums1.size()%2) return nums1[nums1.size()/2];
            else return ((double)nums1[nums1.size()/2]+(double)nums1[nums1.size()/2-1])/2;
        }
        // 在较短的数组中，找到一个下标正好满足分开条件,（右侧元素数量可以多一个）
        bool re=nums1.size()<=nums2.size(); // 数组1的数量大于数组2的数量
        int l=-1,r=re?nums1.size()-1:nums2.size()-1,c,co; // 下标可能出现位置的下标
        int al,ar,bl,br;
        while(l<=r){
            c=(l+r)>>1;
            co=(nums1.size()+nums2.size())/2-c-2;
            // cout<<"index: "<<c<<" "<<co<<endl;
            if(re){
                if(c==-1) al=INT_MIN; else al=nums1[c];
                if(c==nums1.size()-1) ar=INT_MAX; else ar=nums1[c+1];
                if(co==-1) bl=INT_MIN; else bl=nums2[co];
                if(co==nums2.size()-1) br=INT_MAX; else br=nums2[co+1];
            }else{
                if(c==-1) al=INT_MIN; else al=nums2[c];
                if(c==nums2.size()-1) ar=INT_MAX; else ar=nums2[c+1];
                if(co==-1) bl=INT_MIN; else bl=nums1[co];
                if(co==nums1.size()-1) br=INT_MAX; else br=nums1[co+1];
            }
            if(al<=br&&bl<=ar){
                if((nums1.size()+nums2.size())%2) return min(ar,br); // 奇数个
                else return ((double)max(al,bl)+(double)min(ar,br))/2;
            }else if(ar<bl){
                l=c+1;
            }else if(al>br){
                r=c-1;
            }
        }
        return 0;
    }
};