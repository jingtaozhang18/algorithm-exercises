// https://leetcode-cn.com/problems/largest-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int a, int b){
            long long x=a, y=b, aa=a, bb=b;
            // 错误点：0算是一位数字
            if(a==0) y*=10;
            if(b==0) x*=10;
            while(a) y*=10, a/=10;
            while(b) x*=10, b/=10;
            return y+aa<x+bb;
        };
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        // 错误点： 会出现多余的前缀0
        for(auto &e:nums) if(ans.size()!=1||ans[0]!='0'||e!=0) ans+=to_string(e);
        return ans;
    }
};