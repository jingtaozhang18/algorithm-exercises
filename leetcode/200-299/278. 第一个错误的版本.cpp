// https://leetcode-cn.com/problems/first-bad-version/
#include<bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right=n, center;
        while(left<=right){
            center=left+(right-left)/2;
            if(isBadVersion(center)) right=center-1;
            else left=center+1;
        }
        return left;
    }
};