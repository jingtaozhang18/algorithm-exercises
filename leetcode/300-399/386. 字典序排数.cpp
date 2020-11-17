// https://leetcode-cn.com/problems/lexicographical-numbers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(int base, int n, vector<int>&ans){
        int i,t;
        for(i=0;(t=base*10+i)<=n&&i<10;++i){
            if(t) {
                ans.push_back(base*10+i);
                jgo(t,n,ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        jgo(0,n,ans);
        return ans;
    }
};