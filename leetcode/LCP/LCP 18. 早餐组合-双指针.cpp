// https://leetcode-cn.com/problems/2vYnGI/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int i=0,j=drinks.size()-1,ans=0;
        for(;i<staple.size();++i){
            for(;j>=0&&staple[i]+drinks[j]>x;--j);
            ans+=(j+1)%1000000007;
            ans%=1000000007;
        }
        return ans;
    }
};