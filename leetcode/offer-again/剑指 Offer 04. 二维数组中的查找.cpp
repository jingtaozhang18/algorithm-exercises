// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=m?matrix[0].size():0, i=0, j=n-1;
        if(!m||!n) return false;
        while(i<m&&j>=0){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) --j;
            else ++i;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
