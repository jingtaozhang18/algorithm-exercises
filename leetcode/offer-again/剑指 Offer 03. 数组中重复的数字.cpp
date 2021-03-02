// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i, n=nums.size();
        for(i=0;i<n;++i){
            while(nums[i]!=i){
                if(nums[nums[i]]==nums[i]) return nums[i];
                swap(nums[nums[i]], nums[i]);
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
