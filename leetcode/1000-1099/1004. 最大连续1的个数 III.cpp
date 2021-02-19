// https://leetcode-cn.com/problems/max-consecutive-ones-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left=0, size=A.size(), right=0, acc=0, ans=0;
        while(right<size){
            if(A[right++]==0) acc++;
            while(left<right&&acc>K) if(A[left++]==0) acc--;
            ans=max(ans, right-left);
        }
        return ans;
    }
};