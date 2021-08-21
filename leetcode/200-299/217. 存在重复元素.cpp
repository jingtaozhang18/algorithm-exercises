// https://leetcode-cn.com/problems/contains-duplicate/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
    }
};