// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 在较短的数组中，找到一个下标正好满足分开条件,（右侧元素数量可以多一个）
        vector<int> *arr_a, *arr_b;
        if(nums1.size()<=nums2.size()) arr_a=&nums1, arr_b=&nums2;
        else arr_a=&nums2, arr_b=&nums1;
        int len_a=(*arr_a).size(), len_b=(*arr_b).size();
        if(!len_a){
            if(len_b%2) return (*arr_b)[len_b/2];
            else return ((double)(*arr_b)[len_b/2]+(double)(*arr_b)[len_b/2-1])/2;
        }
        int l=-1,r=len_a-1,c,co; // 下标可能出现位置的下标
        int al,ar,bl,br;
        while(l<=r){
            c=(l+r)>>1;
            co=(len_a+len_b)/2-c-2;
            // cout<<"index: "<<c<<" "<<co<<endl;
            if(c==-1) al=INT_MIN; else al=(*arr_a)[c];
            if(c==len_a-1) ar=INT_MAX; else ar=(*arr_a)[c+1];
            if(co==-1) bl=INT_MIN; else bl=(*arr_b)[co];
            if(co==len_b-1) br=INT_MAX; else br=(*arr_b)[co+1];
            if(al<=br&&bl<=ar){
                if((len_b+len_a)%2) return min(ar,br); // 奇数个
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