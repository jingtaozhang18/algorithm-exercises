// https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int arr[51], i;
        for(i=0;i<51;++i) arr[i]=0;
        for(auto &e:ranges){
            for(i=e[0];i<=e[1];++i) {
                arr[i]++;
            }
        }
        for(i=left;i<=right;++i){
            if(arr[i]==0) return false;
        }
        return true;
    }
};