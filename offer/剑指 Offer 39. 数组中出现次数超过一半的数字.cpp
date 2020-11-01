// https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candi;
        for(int c:nums){
            if(!count) candi=c,count=1;
            else{
                if(c==candi) count++;
                else count--;
            }
        }
        return candi;
    }
};