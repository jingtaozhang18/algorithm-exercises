// https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int KT) {
        int m=matrix.size(), n=matrix[0].size(), i, j, k, sum;
        int arr[n];
        set<int> st;
        int ans=INT_MIN;
        for(i=0;i<m;++i){
            for(k=0;k<n;++k) arr[k]=0;
            for(j=i;j<m;++j){
                for(k=0;k<n;++k) arr[k]+=matrix[j][k];
                sum=0; st.clear();
                st.insert(0);
                for(k=0;k<n;++k){
                    sum+=arr[k];
                    auto p=st.lower_bound(sum-KT);
                    if(p!=st.end()){
                        ans=max(ans, sum-*p);
                    }
                    st.insert(sum);
                }
            }
        }
        return ans;
    }
};