// https://leetcode-cn.com/problems/number-of-subarrays-with-bounded-maximum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int left=0, right=0, size=A.size(), ans=0, near=-1;
        while(right<size){
            if(L<=A[right]&&A[right]<=R) ans+=(right-left+1), near=right;
            else if(A[right]<L) {if(near!=-1) ans+=near-left+1;}
            else left=right+1, near=-1;
            ++right;
        }
        return ans;
    }
};