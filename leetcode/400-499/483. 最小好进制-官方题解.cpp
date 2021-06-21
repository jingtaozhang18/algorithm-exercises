// https://leetcode-cn.com/problems/smallest-good-base/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long nVal = stol(n);
        int mMax = floor(log(nVal) / log(2));
        for (int m = mMax; m > 1; m--) {
            int k = pow(nVal, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == nVal) {
                return to_string(k);
            }
        }
        return to_string(nVal - 1);
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/smallest-good-base/solution/zui-xiao-hao-jin-zhi-by-leetcode-solutio-csqn/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。