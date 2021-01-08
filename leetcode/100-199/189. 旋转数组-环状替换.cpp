// https://leetcode-cn.com/problems/rotate-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int x,int y){
        return y?gcd(y,x%y):x;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(), i, t, x;
        k%=n;
        int g=gcd(n, k); // 迭代次数
        int times=n/g; // 每轮需要替换的次数
        i=0;
        while(g--){
            t=times+1;
            while(t--){
                swap(x, nums[i]);
                i=(i+k)%n;
            }
            ++i;
        }
    }
};