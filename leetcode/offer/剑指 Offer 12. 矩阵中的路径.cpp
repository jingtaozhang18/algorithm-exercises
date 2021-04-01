// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can(vector<vector<char> >& board, string& word, vector<vector<bool> >& mem, vector<vector<int> >&dir, int i, int j, int k){
        if(word[k]!=board[i][j]||mem[i][j]) return false;
        if(k==word.size()-1) return true;
        mem[i][j]=true;
        int row=board.size(), col=board[0].size(), ii, jj;
        for(int x=0;x<dir.size();++x){
            ii=i+dir[x][0], jj=j+dir[x][1];
            if(!(ii>=0&&ii<row)) continue;
            if(!(jj>=0&&jj<col)) continue;
            if(can(board, word, mem, dir, ii, jj, k+1)) return true;
        }
        mem[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        vector<vector<int> > dir(4,vector<int>(2,0));
        dir[0][0]=-1,dir[0][1]=0;
        dir[1][0]=1,dir[1][1]=0;
        dir[2][0]=0,dir[2][1]=-1;
        dir[3][0]=0,dir[3][1]=1;
        int row=board.size(), col=board[0].size(),i,j;
        vector<vector<bool> > mem(row, vector<bool>(col, false));
        for(i=0;i<row;++i){
            for(j=0;j<col;++j){
                if(can(board, word, mem, dir, i, j, 0)) return true;
            }
        }
        return false;
    }
};

// 复习
class Solution {
public:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    bool jgo(vector<vector<char>>&board, vector<vector<bool>>&seen, string word, int i, int j, int index){
        if(seen[i][j]) return false;
        if(index==word.size()) return true;
        if(board[i][j]!=word[index]) return false; // 错误点，应对没有机会遍历index+1的情况
        if(index==word.size()-1) return true;
        seen[i][j]=true;  // 想好什么时候添加标记位
        int m=board.size(), n=board[0].size();
        for(int k=0;k<4;++k){
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x>=0&&x<m&&y>=0&&y<n){
                if(jgo(board, seen, word, x, y, index+1)){seen[x][y]=false; return true;}
            }
        }
        seen[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size(), i, j;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        if(word.empty()) return true;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(jgo(board, seen, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};