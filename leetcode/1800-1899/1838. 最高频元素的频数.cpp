// https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/
#include<bits/stdc++.h>
using namespace std;

// 执行效率很低
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> mp;
        map<int, int>::iterator p, q;
        int ans=0, x, y, kk;
        for(auto &e:nums) mp[e]++;
        for(p=mp.begin();p!=mp.end();++p){
            x=p->second, kk=k;
            if(p!=mp.begin()){
                q=p, --q;
                while(kk>0){
                    y=min(q->second, kk/(p->first-q->first));
                    x+=y;
                    kk-=y*(p->first-q->first);
                    if(q==mp.begin()||y==0) break;
                    --q;
                }
            }
            ans=max(ans, x);
        }
        return ans;
    }
};