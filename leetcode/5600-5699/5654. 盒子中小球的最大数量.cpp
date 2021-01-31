// https://leetcode-cn.com/contest/weekly-contest-226/problems/maximum-number-of-balls-in-a-box/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jcalc(int n){
        int ans=0;
        // cout<<n<<" ";
        while(n) ans+=(n%10), n/=10;
        // cout<<ans<<endl;
        return ans;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> map;
        for(int i=lowLimit;i<=highLimit;++i){
            map[jcalc(i)]++;
        }
        int maxv=0;
        for(auto p:map){
            if(p.second>maxv) maxv=p.second;
        }
        return maxv;
    }
};