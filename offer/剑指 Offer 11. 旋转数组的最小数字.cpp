// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==0) return -1;
        int left=0, right=numbers.size()-1, mid;
        while(left<right){
            if(numbers[left]<numbers[right]) return numbers[left];
            mid=(left+right)>>1;
            if(numbers[left]<numbers[mid]) left=mid+1;
            else if(numbers[left]>numbers[mid]) right=mid;
            else {
                for(int i=left;i<=right;++i) if(numbers[i]<numbers[left]) return numbers[i];
                return numbers[left];
            }
        }
        return numbers[left];
    }
};