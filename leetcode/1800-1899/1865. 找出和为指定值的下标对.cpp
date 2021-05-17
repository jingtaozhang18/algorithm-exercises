// https://leetcode-cn.com/problems/finding-pairs-with-a-certain-sum/
#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    multiset<int> st;
    unordered_map<int, int> mp; // 测试数据有点变态
    vector<int> nums2;
    FindSumPairs(vector<int>& nms1, vector<int>& nms2) {
        for(auto e:nms1) mp[e]++;
        nums2 = vector<int>(nms2);
        st = multiset(nms2.begin(), nms2.end());
    }
    
    void add(int index, int val) {
        auto p = st.find(nums2[index]);
        st.erase(p);
        nums2[index]+=val;
        st.insert(nums2[index]);
    }
    
    int count(int tot) {
        int ans=0;
        for(auto p:mp) ans+=st.count(tot-p.first)*p.second;
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */