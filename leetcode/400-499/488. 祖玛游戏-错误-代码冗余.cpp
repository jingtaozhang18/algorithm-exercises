// https://leetcode-cn.com/problems/zuma-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jclean(vector<char>& arr){ // 单次清理
        int i,j,size=arr.size();
        for(i=1,j=0;i<size;++i){
            if(arr[j]==arr[i]) continue;
            else{
                if(i-j>=3){ // 进行清理
                    arr.erase(arr.begin()+j, arr.begin()+i);
                    return true;
                }
                j=i;
            }
        }
        if(i-j>=3){ // 进行清理
            arr.erase(arr.begin()+j, arr.begin()+i);
            return true;
        }
        return false;
    }
    int jgo(vector<char> board, map<char,int> hand){
        int ans=INT_MAX, i,j,size=board.size(),need,t;
        if(size==0) return 0;
        vector<char> tb;
        for(i=1,j=0;i<size;++i){
            if(board[j]==board[i]) continue;
            else{
                need=3-i+j;
                if(hand[board[j]]>=need){
                    // 消除
                    tb=vector<char>(board);
                    tb.erase(tb.begin()+j, tb.begin()+i);
                    while(jclean(tb));
                    hand[board[j]]-=need;
                    t=jgo(tb, hand);
                    if(t!=INT_MAX)ans=min(ans, need+t);
                    hand[board[j]]+=need;
                }
                j=i;
            }
        }
        need=3-i+j;
        if(hand[board[j]]>=need){
            tb=vector<char>(board);
            tb.erase(tb.begin()+j, tb.begin()+i);
            while(jclean(tb));
            hand[board[j]]-=need;
            t=jgo(tb, hand);
            if(t!=INT_MAX)ans=min(ans, need+t);
            hand[board[j]]+=need;
        }
        return ans;
    }
    int findMinStep(string board, string hand) {
        // 换成数组结构方便数据处理
        int m=board.size(), n=hand.size(), i, ans;
        vector<char> vboard(m);
        map<char, int> mp; mp['R']=mp['Y']=mp['B']=mp['G']=mp['W']=0;
        for(i=0;i<m;++i) vboard[i]=board[i];
        for(i=0;i<n;++i) mp[hand[i]]++;
        while(jclean(vboard));
        ans=jgo(vboard, mp);
        return ans==INT_MAX?-1:ans;
    }
};