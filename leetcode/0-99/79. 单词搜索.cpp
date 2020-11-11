// https://leetcode-cn.com/problems/word-search/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dir[4][2]{-1,0, 1,0, 0,-1, 0,1};
    bool jgo(vector<vector<char>>& board, vector<vector<bool>>& mem, string s, int i, int a, int b){
        int x,y,m=board.size(), n=board[0].size(),l;
        if(i==s.size()) return true;
        if(s[i]!=board[a][b]||mem[a][b]) return false;
        if(i==s.size()-1) return true; // 错误点: 最后一个位置没有必要探索了
        mem[a][b]=true;
        for(l=0;l<4;++l){
            x=a+dir[l][0], y=b+dir[l][1];
            if(x>=0&&x<m&&y>=0&&y<n) if(jgo(board, mem, s, i+1, x, y)) return true;
        }
        mem[a][b]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> mem(board.size(), vector<bool>(board[0].size(), false));
        int i,j;
        for(i=0;i<board.size();++i){
            for(j=0;j<board[i].size();++j){
                if(jgo(board, mem, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};