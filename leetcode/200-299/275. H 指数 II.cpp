// https://leetcode-cn.com/problems/h-index-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int m=citations.size(), left=0, right=m-1, center;
        while(left<=right){
            center=left+(right-left)/2;
            if(m-center<=citations[center]) right=center-1;
            else left=center+1;
        }
        return m-left;
    }
};
