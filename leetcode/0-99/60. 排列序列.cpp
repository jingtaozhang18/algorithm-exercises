// https://leetcode-cn.com/problems/permutation-sequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int vec[n+1], st[n+1], i, j;
        vec[0]=1;
        for(i=1;i<=n;++i) vec[i]=vec[i-1]*i, st[i]=false;
        int acc=0;
        string ans(n, ' ');
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                if(st[j]==false){
                    if(acc+vec[n-i]>=k) {
                        st[j]=true;
                        ans[i-1]='0'+j;
                        break;
                    } else{
                        acc+=vec[n-i];
                    } 
                }
            }
        }
        return ans;
    }
};