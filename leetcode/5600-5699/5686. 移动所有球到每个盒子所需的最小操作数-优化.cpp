// https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int i, size=boxes.size(), left=0, right=0, total=0; // left 左侧1的个数， right 右侧1的个数 total，初始化为位置0的移动次数
        vector<int> ans(size);
        for(i=1;i<size;++i){
            if(boxes[i]=='1') right++, total+=i;
        }
        ans[0]=total;
        for(i=1;i<size;++i){
            if(boxes[i-1]=='1') left++; // 更改左侧1的个数
            total=total+left-right; // 所有左侧1增加一个移动成本， 右侧的1减少一个移动成本
            if(boxes[i]=='1') right--; // 注意修改的顺序
            ans[i]=total;
        }
        return ans;
    }
};