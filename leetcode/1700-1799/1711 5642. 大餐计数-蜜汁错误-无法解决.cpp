// https://leetcode-cn.com/problems/count-good-meals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator p;
        unordered_map<int, int>::iterator op;
        set<int> st;
        int i, ans=0, sum, diff, m=1e9+7,acc;
        for(auto e:deliciousness) mp[e]++;
        for(p=mp.begin();p!=mp.end();++p){
            for(sum=1,i=0;i<21;i++){
                diff=sum-p->first;
                if(diff>=0&&(op=mp.find(diff))!=mp.end()&&st.find(diff)==st.end()){
                    if(diff==p->first) acc=(p->second*(p->second-1)/2);
                    else acc=(p->second*op->second);
                    // printf("%d:%d, %d:%d :%d\n", p->first, p->second, op->first, op->second, acc);
                    ans+=acc, ans%=m;
                }
                sum<<=1;
            }
            st.insert(p->first);
        }
        return ans;
    }
};