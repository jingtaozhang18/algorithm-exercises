// https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int label2index(int level[], int label, int k, int acc){
        label -= acc;
        if(k%2==0){
            return label-1;
        }else{
            return level[k]-label;
        }
    }
    int index2label(int level[], int index, int k, int acc){
        int label;
        label = acc;
        if(k%2==0){
            label+=index+1;
        }else{
            label+=level[k]-index;
        }
        return label;
    }
    vector<int> pathInZigZagTree(int label) {
        int level[100], i, k, acc=0, x=1;
        while(acc<label){
            level[k]=x;
            acc+=level[k];
            ++k, x<<=1;
        }
        --k, acc-=level[k]; // 层级 偶数正向，计数反向
        vector<int> ans(k+1);
        i=k;
        while(k>=0){
           ans[k]=label;
           x=label2index(level, label, k, acc);
           x>>=1;
           --k;
           if(k>=0){
               acc-=level[k];
               label = index2label(level, x, k, acc);
           }
        }
        return ans;
    }
};