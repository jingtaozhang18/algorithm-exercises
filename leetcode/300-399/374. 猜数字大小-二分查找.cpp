// https://leetcode-cn.com/problems/guess-number-higher-or-lower/
#include<bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left=1, right=n,mid,t; // 错误点 大int相加会越界
        while(left<=right){
            mid=(left+right)>>1;
            t=guess(mid);
            if(t==0) return mid;
            else if(t==-1) right=mid-1; // 实际的要小
            else left=mid+1; // 实际的要大
        }
        return -1;
    }
};