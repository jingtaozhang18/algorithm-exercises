// https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int i, j, x, a, ans=INT_MAX, n=nums.size();
        // 分组放入
        vector<unordered_map<int, int>> arr(k, unordered_map<int, int>());
        vector<int> size(k); // 每一组的数量
        for(i=0;i<n;++i) arr[i%k][nums[i]]++, size[i%k]++;
        // 转移
        vector<int> dp(1<<10, 2000); // 默认起始分区，0需要更改的元素是0，其他值需要更改的数量是无限大
        dp[0] = 0;
        for(i=0;i<k;++i){
            // 任何一个值的最大可能性
            vector<int> ndp(1<<10, *min_element(dp.begin(), dp.end())+size[i]);
            // 只需要考虑转换的值是自己已经有的值
            for(auto e:arr[i]){
                int p = e.first;
                int freq = e.second;
                for(j=0;j<1<<10;++j){ // 总的转移次数是n*1024
                    ndp[p^j] = min(ndp[p^j], dp[j]+size[i]-freq);
                }
            }
            dp = move(ndp);
        }
        return dp[0];
    }
};