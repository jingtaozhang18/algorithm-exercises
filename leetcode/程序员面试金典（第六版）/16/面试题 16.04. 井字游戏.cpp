// https://leetcode-cn.com/problems/tic-tac-toe-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<string>& board) {
        bool done=true;
        int i,j,m=board.size(),n=board[0].size();
        char ans;
        for(i=0;i<m;++i){
            ans=board[i][0];
            if(ans==' '){
                done=false;
                continue;
            }
            for(j=1;j<n;++j){
                if(board[i][j]!=ans) break;
            }
            if(j==n) return string(1,ans);
            if(done){
                for(;j<n;++j){
                    if(board[i][j]==' '){
                        done=false;
                        break;
                    }
                }
            }
        }
        for(i=0;i<n;++i){
            ans=board[0][i];
            if(ans==' '){
                done=false;
                continue;
            }
            for(j=1;j<m;++j){
                if(board[j][i]!=ans) break;
            }
            if(j==m) return string(1,ans);
            if(done){
                for(;j<m;++j){
                    if(board[j][i]==' '){
                        done=false;
                        break;
                    }
                }
            }
        }
        if(board[0][0]!=' '){
            for(i=1;i<m;++i){
                if(board[i][i]!=board[i-1][i-1]){
                    break;
                }
            }
            if(i==m)
            return string(1, board[0][0]);
        }
        if(board[0][n-1]!=' '){
            for(i=1;i<m;++i){
                if(board[i][n-i-1]!=board[i-1][n-i]){
                    break;
                }
            }
            if(i==m)
            return string(1, board[0][n-1]);
        }
        if(done) return "Draw";
        return "Pending";
    }
};