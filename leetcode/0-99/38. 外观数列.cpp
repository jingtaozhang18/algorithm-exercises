// https://leetcode-cn.com/problems/count-and-say/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int arr[2][10000], i, j, acc, val, k;
        arr[0][0]=1, arr[0][1]=0;
        for(i=0;i<n;++i){
            // 处理arr[i%2], 填充arr[(i+1)%2]
            acc=0, val=-1;
            for(j=k=0;arr[i%2][j]!=0;++j){
                if(val!=arr[i%2][j]){
                    if(val!=-1){
                        arr[(i+1)%2][k++]=acc;
                        arr[(i+1)%2][k++]=val;
                    }
                    val=arr[i%2][j], acc=1;
                }else acc++;
            }
            arr[(i+1)%2][k++]=acc, arr[(i+1)%2][k++]=val, arr[(i+1)%2][k]=0;
        }
        string ans(10000, ' ');
        for(i=0;arr[(n+1)%2][i]!=0;++i) ans[i]='0'+arr[(n+1)%2][i];
        return ans.substr(0, i);
    }
};