// https://leetcode-cn.com/problems/pond-sizes-lcci/
#include<bits/stdc++.h>
using namespace std;

struct junion{
    vector<int> arr;
    junion(int n){arr=vector<int>(n); for(int i=0;i<n;++i) arr[i]=i;}
    int find(int index){
        if(arr[index]==index) return index;
        return arr[index]=find(arr[index]);
    }
    void ui(int i, int j){
        i=find(i), j=find(j);
        if(i!=j) arr[i]=j;
    }
};

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m=land.size(), n=land[0].size(), i, j, k, x, y;
        junion un(m*n);
        int dir[16]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(land[i][j]!=0) continue;
                for(k=0;k<16;k+=2){
                    x=i+dir[k], y=j+dir[k+1];
                    if(x>=0&&x<m&&y>=0&&y<n&&land[x][y]==0){
                        un.ui(i*n+j, x*n+y);
                    }
                }
            }
        }
        unordered_map<int, int> mp;
        for(i=0;i<m*n;++i){
            if(land[i/n][i%n]==0){
                mp[un.find(i)]++;
            }
        }
        vector<int> ans;
        for(auto p=mp.begin();p!=mp.end();++p){
            ans.push_back(p->second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};