// https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jcmp(string &a, string &b){
        if(a.size()==b.size()) return a<b;
        return a.size()<b.size();
    }
    string addChar(string a, int x){
        a.resize(a.size()+1);
        int m=a.size(), i;
        a[m-1]='0'+x;
        for(i=m-1;i>0;--i){
            if(a[i-1]<a[i]) swap(a[i-1], a[i]);
            else break;
        }
        return a;
    }
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1);
        string x, y;
        int i, j;
        for(i=0;i<9;++i){
            for(j=cost[i];j<=target;++j){ // 添加成本
                if(j-cost[i]==0) x='0'+i+1;
                else if(dp[j-cost[i]].size()) x=addChar(dp[j-cost[i]], i+1);
                else x="";
                if(jcmp(dp[j], x)) dp[j]=x;
            }
        }
        return dp[target].size()==0?"0":dp[target];
    }
};
