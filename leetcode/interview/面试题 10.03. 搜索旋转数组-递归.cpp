// https://leetcode-cn.com/problems/search-rotate-array-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& arr, int l, int r, int tar){
        int c, rr=r;
        int ans=-1;
        if(l==r){ // 终止条件
            if(arr[l]==tar) return l;
            else return -1;
        }
        if(arr[l]<arr[r]) { // 整个区域有序
            while(l<=r){
                c=l+(r-l)/2;
                if(tar<=arr[c]) r=c-1;
                else l=c+1;
            }
            return (l<=rr&&arr[l]==tar)?l:-1; // 多多练习
        }else{
            if(tar>arr[r]&&tar<arr[l]) return -1; // 即使终止
            c=l+(r-l)/2;
            ans=jgo(arr, l, c, tar); // 可能会产生死循环，需要判断终止条件
            ans=ans==-1?jgo(arr, c+1, r, tar):ans;
        }
        return ans;
    }
    int search(vector<int>& arr, int target) {
        return jgo(arr, 0, arr.size()-1, target);
    }
};