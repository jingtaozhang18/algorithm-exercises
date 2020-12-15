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