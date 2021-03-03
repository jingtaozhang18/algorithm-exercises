// https://leetcode-cn.com/problems/counting-bits/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(int i){
        int ans=0;
        while(i%2==0) ans++, i/=2;
        return ans;
    }
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        int i;
        for(i=1;i<=num;++i){
            ans[i]=ans[i-1]+1;
            if(i%2==0) ans[i]-=jgo(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for(int i=1;i<=num;++i){
            ans[i]=ans[i&(i-1)]+1; // 最低设置位
        }
        return ans;
    }
};