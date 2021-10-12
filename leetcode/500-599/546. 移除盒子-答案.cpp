// https://leetcode-cn.com/problems/remove-boxes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dp[100][100][100];

  int removeBoxes(vector<int>& boxes) {
    memset(dp, 0, sizeof dp);
    return calculatePoints(boxes, 0, boxes.size() - 1, 0);
  }

  int calculatePoints(vector<int>& boxes, int l, int r, int k) {
    if (l > r) {
      return 0;
    }
    if (dp[l][r][k] == 0) {
      dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
      for (int i = l; i < r; i++) {
        if (boxes[i] == boxes[r]) {
          dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
        }
      }
    }
    return dp[l][r][k];
  }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/remove-boxes/solution/yi-chu-he-zi-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。