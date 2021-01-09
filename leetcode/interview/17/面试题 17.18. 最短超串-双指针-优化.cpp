// https://leetcode-cn.com/problems/shortest-supersequence-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map<int, int> need; // 只是用一个哈希记录
        for(auto e: small) need[e]++;
        int size=big.size(), left=0, right=0, ansl=-1, ansr, miss=small.size(), mina=INT_MAX, c;
        while(right<size){
            c=big[right];
            need[c]--;
            if(need[c]>=0) miss--;
            if(miss==0){
                // 全都包含， 开始从做开始移除数据
                while(left<=right){
                    c=big[left];
                    if(need[c]<0) need[c]++, left++;
                    else break;
                }
                if(right-left+1<mina){
                    ansl=left, ansr=right, mina=right-left+1;
                }
            }
            right++;
        }
        if(ansl==-1) return vector<int>();
        return vector<int>{ansl, ansr};
    }
};