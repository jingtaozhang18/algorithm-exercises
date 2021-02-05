// https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i, j, ans=0, val, size=s.size(), left, right, mid;
        vector<int> diff(size+1);
        diff[0]=0;
        for(i=0;i<size;++i) diff[i+1]=diff[i]+abs((int)s[i]-(int)t[i]);
        // [i, j]消耗的是diff[j+1]-diff[i];
        for(j=1;j<=size;++j){
            val=diff[j]-maxCost; // 允许的最小值
            left=0, right=j-1;
            while(left<=right){
                mid=left+(right-left)/2;
                if(diff[mid]<val) left=mid+1;
                else right=mid-1;
            }
            ans=max(ans, j-left);
        }
        return ans;
    }
};