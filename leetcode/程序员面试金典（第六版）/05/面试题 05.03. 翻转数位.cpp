// https://leetcode-cn.com/problems/reverse-bits-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        vector<int> arr;
        unsigned int flag=1, i, acc=0;
        for(i=0;i<=32;++i){
            if(i<32&&num&flag) acc++;
            else{
                arr.push_back(acc);
                acc=0;
            }
            flag<<=1;
        }
        if(arr.size()==1) return min(32, arr[0]+1);
        int ans=0;
        for(i=0;i<arr.size()-1;++i){
            ans=max(ans, arr[i]+arr[i+1]+1);
        }
        return ans;
    }
};