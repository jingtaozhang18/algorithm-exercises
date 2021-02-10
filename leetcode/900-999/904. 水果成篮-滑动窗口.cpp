// https://leetcode-cn.com/problems/fruit-into-baskets/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> map;
        int left=0, right=0, size=tree.size(), ans=0;
        while(right<size){
            ++map[tree[right++]];
            while(map.size()>2){
                if(--map[tree[left]]==0) map.erase(tree[left]);
                left++;
            }
            ans=max(right-left, ans);
        }
        return ans;
    }
};