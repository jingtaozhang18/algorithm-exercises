// https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long jgo(long prefix, long n){ // 计算prefix为前缀的数量
        long cur=prefix, next=prefix+1, ans=0; // 当前节点的右节点为右边界，一层一层的进行计算
        while(cur<=n) ans+=min(n+1, next)-cur,cur*=10,next*=10;
        return ans;
    }
    int findKthNumber(int n, int k) {
        long cur=0, index=0, i, t, prefix;
        while(index<=k){
            for(i=0;i<10;++i){
                if(cur==0&&i==0) continue; // 跳过0
                prefix=cur+i;
                t=jgo(prefix, n);
                if(index+t>=k){ // 进入 错误点，在相等的时候也说明是该分支下面的
                    index++;
                    if(index==k) return prefix; // 错误点，在index发生变化的时候就需要判断
                    cur=prefix*10;
                    break;
                }else if(index+t<k){ // 选择下个节点
                    index+=t;
                }
                if(index==k) return prefix;
            }
        }
        return -1;
    }
};