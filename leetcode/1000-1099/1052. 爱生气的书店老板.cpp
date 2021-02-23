// https://leetcode-cn.com/problems/grumpy-bookstore-owner/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int i, acc=0, ans=0, ans_i=-1, ans_s=0, size=customers.size();
        // (ans_i-X, ans_i] 这段时间惹怒的客户数量最多
        for(i=0;i<size;++i){
            acc+=grumpy[i]*customers[i];
            if(i>=X-1){
                if(acc>ans_s){
                    ans_s=acc;
                    ans_i=i;
                }
                acc-=grumpy[i-X+1]*customers[i-X+1];
            }
            ans+=(1-grumpy[i])*customers[i];
        }
        ans+=ans_s;
        return ans;
    }
};