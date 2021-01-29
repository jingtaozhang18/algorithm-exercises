// https://leetcode-cn.com/problems/find-longest-subarray-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int i=0, size=array.size(), acc=0, ans=-1, length=-1;
        unordered_map<int, int> mp;
        mp[0]=-1; // 初始化一个状态
        for(i=0;i<size;++i){
            if(("A"<=array[i]&&array[i]<="Z")||("a"<=array[i]&&array[i]<="z")) acc++;
            else acc--;
            if(mp.find(acc)==mp.end()) mp[acc]=i;
            else {
                if(i-mp[acc]>length){
                    ans=mp[acc], length=i-mp[acc];
                }
            }
        }
        vector<string> res;
        if(length==-1) return res;
        for(i=ans+1;i<=ans+length;++i) res.push_back(array[i]);
        return res;
    }
};