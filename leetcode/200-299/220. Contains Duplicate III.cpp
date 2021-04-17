// https://leetcode-cn.com/problems/re-space-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        queue<int> que;
        multiset<int> st;
        for(auto &e:nums){
          que.push(e);
          auto p = st.lower_bound(e);
          if(p!=st.end()&&abs((long long)*p-e)<=t) return true;
          if(st.size()&&p!=st.begin()&&abs((long long)*(--p)-e)<=t) return true;
          st.insert(e);
          if(que.size()==k+1){
            st.erase(st.find(que.front()));
            que.pop();
          }
        }
        return false;
    }
};