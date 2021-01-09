// https://leetcode-cn.com/problems/shortest-supersequence-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map<int, int> need;
        unordered_map<int, int> have;
        for(auto e: small) need[e]++;
        int size=big.size(), left=0, right=0, ansl=-1, ansr, miss=small.size(), mina=INT_MAX;
        while(right<size){
            int c=big[right];
            if(need[c]) {
                have[c]++;
                if(have[c]<=need[c]) miss--;
            }
            if(miss==0){
                // 全都包含， 开始从做开始移除数据
                while(left<=right){
                    c=big[left];
                    if(need[c]){
                        if(have[c]>need[c]){
                            have[c]--;
                            left++;
                        }else{
                            break;
                        }
                    }else{
                        left++;
                    }
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