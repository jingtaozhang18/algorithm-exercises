// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& arr, int k){ // 不超过K种数字的子数组个数
        unordered_map<int, int> map;
        int left=0, right=0, size=arr.size(), ans=0;
        while(right<size){
            ++map[arr[right++]];
            while(map.size()>k){
                --map[arr[left]];
                if(map[arr[left]]==0) map.erase(arr[left]);
                left++;
            }
            ans+=right-left;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return jgo(A, K)-jgo(A, K-1);
    }
};