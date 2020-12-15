// https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    int x=a,y=b,len_x=0,len_y=0;
    if(!x) len_x=1;
    else while(x) len_x++, x/=10;
    if(!y) len_y=1;
    else while(y) len_y++, y/=10;
    return a*pow(10, len_y)+b < b*pow(10, len_x)+a;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        int i;
        string ans="";
        sort(nums.begin(), nums.end(), cmp);
        for(i=0;i<nums.size();++i) ans.append(to_string(nums[i]));
        return ans;
    }
};