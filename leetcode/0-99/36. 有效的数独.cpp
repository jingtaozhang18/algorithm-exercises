// https://leetcode-cn.com/problems/valid-sudoku/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, a, b, acc;
        unordered_set<char> st;
        for(i=0;i<9;++i){
            st.clear(); acc=0;
            for(j=0;j<9;++j) if(board[i][j]!='.') st.insert(board[i][j]); else acc++;
            if(st.size()+acc!=9) return false;
        }
        for(i=0;i<9;++i){
            st.clear(); acc=0;
            for(j=0;j<9;++j) if(board[j][i]!='.') st.insert(board[j][i]); else acc++;
            if(st.size()+acc!=9) return false;
        }
        for(i=0;i<3;++i){
            for(j=0;j<3;++j) {
                st.clear(); acc=0;
                for(a=0;a<3;++a)
                    for(b=0;b<3;++b)
                        if(board[i*3+a][j*3+b]!='.') st.insert(board[i*3+a][j*3+b]);
                        else acc++;
                if(st.size()+acc!=9) return false;
            }
        }
        return true;
    }
};