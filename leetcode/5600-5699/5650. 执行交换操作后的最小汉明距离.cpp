// https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mem;
    int jfind(int i){
        if(i!=mem[i]) mem[i]=jfind(mem[i]);
        return mem[i];
    }
    void jmerge(int i, int j){
        i=jfind(i);
        j=jfind(j);
        if(i!=j) mem[i]=j;
    }
    int jcount(vector<int>&a, vector<int>& b){ // 计算不同的数量
        int i=0,j=0,size=a.size(),diff=0;
        // for(i=0;i<size;++i) cout<<a[i]<<" ";
        // cout<<endl;
        // for(i=0;i<size;++i) cout<<b[i]<<" ";
        // cout<<endl;
        // i=0;
        while(i<size&&j<size){
            // cout<<i<<" "<<j<<endl;
            if(a[i]==b[j]) ++i, ++j;
            else{
                if(a[i]<b[j]) ++i;
                else ++j;
                ++diff;
            }
        }
        
        diff+=size-i;
        diff+=size-j;
        diff>>=1;
        // cout<<"diff: "<<diff<<endl;
        return diff;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int size=source.size(),i;
        mem=vector<int>(size);
        for(i=0;i<size;++i) mem[i]=i;
        for(auto e:allowedSwaps) jmerge(e[0], e[1]);
        unordered_map<int, vector<int>> mps;
        unordered_map<int, vector<int>> mpt;
        unordered_map<int, vector<int>>::iterator p;
        for(i=0;i<size;++i) mps[jfind(i)].push_back(source[i]);
        for(i=0;i<size;++i) mpt[jfind(i)].push_back(target[i]);
        for(p=mps.begin();p!=mps.end();++p) sort(p->second.begin(), p->second.end());
        for(p=mpt.begin();p!=mpt.end();++p) sort(p->second.begin(), p->second.end());
        int ans=0;
        for(p=mps.begin();p!=mps.end();++p){
            ans+=jcount(p->second, mpt[p->first]);
        }
        return ans;
    }
};