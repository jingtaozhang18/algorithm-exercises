// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i, size=prices.size();
      vector<vector<int>> first(size+1, vector<int>{0, INT_MIN}); // 0:不持有， 1:持有
      vector<vector<int>> second(size+1, vector<int>{0, INT_MIN});
      for(i=0;i<size;++i){
        first[i+1][0]=max(first[i][0], first[i][1]+prices[i]); // 持续不持有或者卖掉
        first[i+1][1]=max(first[i][1], 0-prices[i]); // 持有，买入从开始状态买入
        second[i+1][0]=max(second[i][0], second[i][1]+prices[i]); // 持续不持有或者卖掉
        second[i+1][1]=max(second[i][1], first[i][0]-prices[i]); // 买入只能从第一次买入
      }
      return second[size][0];
    }
};