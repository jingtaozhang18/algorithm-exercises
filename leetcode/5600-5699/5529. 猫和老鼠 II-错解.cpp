// https://leetcode-cn.com/contest/weekly-contest-224/problems/cat-and-mouse-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> mp;
    bool jgo(vector<string>& grid, int catJump, int mouseJump, int a, int b, int c, int d, bool M, int t){ // a, b:C, cd:M
        if(t==1000) return false;
        string key=to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d)+"."+to_string(M);
        cout<<key<<endl;
        if(mp.find(key)!=mp.end()) return mp[key];
        if(a==c&&b==d) return false;
        if(grid[a][b]=='F') return false;
        if(grid[c][d]=='F') return true;
        // 找出可以走的地方
        int i, j, x, y,m=grid.size(),n=grid[0].size();
        if(M){
            for(j=0;j<4;++j){
                for(i=1;i<=mouseJump;++i){
                    if(j==0) x=c-i, y=d;
                    else if(j==1) x=c+i, y=d;
                    else if(j==2) x=c, y=d-i;
                    else x=c, y=d+i;
                    if(x<0||x>=m||y<0||y>=n||grid[x][y]=='#') break;
                    if(jgo(grid, catJump, mouseJump, a, b, x, y, false, t)) return true;
                }
            }
            if(jgo(grid, catJump, mouseJump, a, b, c, d, false, t)) return true;
        }else{
            for(j=0;j<4;++j){
                for(i=1;i<=catJump;++i){
                    if(j==0) x=a-i, y=b;
                    else if(j==1) x=a+i, y=b;
                    else if(j==2) x=a, y=b-i;
                    else x=a, y=b+i;
                    if(x<0||x>=m||y<0||y>=n||grid[x][y]=='#') break;
                    if(grid[x][y]=='F'||(x==c&&y==d)) return mp[key]=false; // 尽快判断该位置老鼠赢不了
                }
            }
            for(j=0;j<4;++j){
                for(i=1;i<=catJump;++i){
                    if(j==0) x=a-i, y=b;
                    else if(j==1) x=a+i, y=b;
                    else if(j==2) x=a, y=b-i;
                    else x=a, y=b+i;
                    if(x<0||x>=m||y<0||y>=n||grid[x][y]=='#') break;
                    if(jgo(grid, catJump, mouseJump, x, y, c, d, true, t+1)) return mp[key]=false;
                }
            }
            if(jgo(grid, catJump, mouseJump, a, b, c, d, true, t+1)) return true;
        }
        return mp[key]=false;
    }
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int a,b,c,d,i,j,m=grid.size(),n=grid[0].size();
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(grid[i][j]=='M') c=i,d=j,grid[i][j]='.';
                if(grid[i][j]=='C') a=i,b=j,grid[i][j]='.';
            }
        }
        return jgo(grid, catJump, mouseJump, a, b, c, d, true, 1);
    }
};