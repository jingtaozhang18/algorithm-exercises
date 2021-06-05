// https://leetcode-cn.com/problems/sudoku-solver/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int index;
    int val;
    node(int index, int val):index(index),val(val){};
    bool operator<(const node& other) const{
        return this->val<other.val;
    }
};

class Solution {
public:
    bool jgo(int index, vector<node>& vec, unordered_map<int, unordered_set<int>>&mp, vector<vector<char>>& board){
        int index_i, index_j, i, j, x, y, a, b, key;
        bool flag;
        if(index==vec.size()) return true;
        auto p=mp.find(vec[index].index);
        index_i=p->first/10, index_j=p->first%10;
        for(auto q=p->second.begin();q!=p->second.end();++q){ // 枚举可能的值 
            board[index_i][index_j]=*q+'0', flag=true;
            for(j=0;j<9;++j){
                if(j!=index_j){
                    key=index_i*10+j;
                    if(mp.find(key)!=mp.end() && board[index_i][j]==board[index_i][index_j]) flag=false;
                }
            }
            if(!flag) continue;
            for(i=0;i<9;++i){
                if(index_i!=i){
                    key=i*10+index_j;
                    if(mp.find(key)!=mp.end() && board[i][index_j]==board[index_i][index_j]) flag=false;
                }
            }
            if(!flag) continue;
            a=index_i/3*3, b=index_j/3*3;
            for(x=0;x<3;++x){
                for(y=0;y<3;++y){
                    i=a+x, j=b+y;
                    // cout<<i<<" "<<j<<", ";
                    key=i*10+j;
                    if(mp.find(key)!=mp.end() && !(i==index_i&&j==index_j) && board[i][j]==board[index_i][index_j]) flag=false;
                }
            }
            // cout<<endl;
            if(!flag) continue;
            if(jgo(index+1, vec, mp, board)) return true;
        }
        board[index_i][index_j]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size(), i, j, k, a, b, x, y, key, index_i, index_j;
        unordered_map<int, unordered_set<int>> mp;
        for(i=0;i<9;++i){
            for(j=0;j<9;++j){
                if(board[i][j]=='.'){
                    key=i*10+j;
                    mp[key]=unordered_set<int>();
                    for(k=1;k<=9;++k) mp[key].insert(k);
                    for(k=0;k<9;++k){
                        if(k==j) continue;
                        if(board[i][k]!='.') mp[key].erase(board[i][k]-'0');
                    }
                    for(k=0;k<9;++k){
                        if(k==i) continue;
                        if(board[k][j]!='.') mp[key].erase(board[k][j]-'0');
                    }
                    a=i/3*3, b=j/3*3;
                    for(x=0;x<3;++x){
                        for(y=0;y<3;++y){
                            if(board[a+x][b+y]!='.') mp[key].erase(board[a+x][b+y]-'0');
                        }
                    }
                }
            }
        }
        vector<node> vec;
        for(auto p=mp.begin();p!=mp.end();++p){
            vec.push_back(node(p->first, p->second.size()));
        }
        sort(vec.begin(), vec.end());
        jgo(0, vec, mp, board);
    }
};