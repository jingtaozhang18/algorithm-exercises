// https://leetcode-cn.com/problems/out-of-boundary-paths/submissions/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int arr[2][m][n], i, j, k, dir[4][2]={-1,0,1,0,0,1,0,-1}, x, y, l, ans=0, mod=1e9+7;
        for(i=0;i<m;++i)for(j=0;j<n;++j) arr[0][i][j]=0;
        arr[0][startRow][startColumn]=1;
        for(k=0;k<maxMove;++k){
            for(i=0;i<m;++i) for(j=0;j<n;++j) arr[(k+1)%2][i][j]=0;
            for(i=0;i<m;++i){
                for(j=0;j<n;++j){
                    if(arr[k%2][i][j]){
                        for(l=0;l<4;++l){
                            x=i+dir[l][0];
                            y=j+dir[l][1];
                            if(x>=0&&x<m&&y>=0&&y<n){
                                arr[(k+1)%2][x][y]+=arr[k%2][i][j];
                                arr[(k+1)%2][x][y]%=mod;
                            }else{
                                ans+=arr[k%2][i][j];
                                ans%=mod;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
