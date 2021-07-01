// https://leetcode-cn.com/problems/sliding-puzzle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jcalc(int arr[]){
        int ans=0;
        for(int i=0;i<6;++i) ans*=10, ans+=arr[i];
        return ans;
    }
    vector<int> jget(int val){ // 得到邻居
        int arr[6], i, m=1e5, p;
        for(i=0;i<6;++i) arr[i]=val/m, val%=m, m/=10, p=arr[i]==0?i:p;
        vector<int> ans;
        if(p==0){
            swap(arr[0], arr[1]); ans.push_back(jcalc(arr)); swap(arr[0], arr[1]);
            swap(arr[0], arr[3]); ans.push_back(jcalc(arr)); swap(arr[0], arr[3]);
        }else if(p==1){
            swap(arr[1], arr[0]); ans.push_back(jcalc(arr)); swap(arr[1], arr[0]);
            swap(arr[1], arr[4]); ans.push_back(jcalc(arr)); swap(arr[1], arr[4]);
            swap(arr[1], arr[2]); ans.push_back(jcalc(arr)); swap(arr[1], arr[2]);
        }else if(p==2){
            swap(arr[2], arr[1]); ans.push_back(jcalc(arr)); swap(arr[2], arr[1]);
            swap(arr[2], arr[5]); ans.push_back(jcalc(arr)); swap(arr[2], arr[5]);
        }else if(p==3){
            swap(arr[3], arr[0]); ans.push_back(jcalc(arr)); swap(arr[3], arr[0]);
            swap(arr[3], arr[4]); ans.push_back(jcalc(arr)); swap(arr[3], arr[4]);
        }else if(p==4){
            swap(arr[4], arr[3]); ans.push_back(jcalc(arr)); swap(arr[4], arr[3]);
            swap(arr[4], arr[1]); ans.push_back(jcalc(arr)); swap(arr[4], arr[1]);
            swap(arr[4], arr[5]); ans.push_back(jcalc(arr)); swap(arr[4], arr[5]);
        }else if(p==5){
            swap(arr[5], arr[4]); ans.push_back(jcalc(arr)); swap(arr[5], arr[4]);
            swap(arr[5], arr[2]); ans.push_back(jcalc(arr)); swap(arr[5], arr[2]);
        }
        return ans;
    } 
    int slidingPuzzle(vector<vector<int>>& board) {
        int arr[6], i, val;
        for(i=0;i<6;++i) arr[i]=board[i/3][i%3];
        val=jcalc(arr);
        if(val==123450) return 0;
        queue<int> que; que.push(val); // bfs搜索
        unordered_map<int, int> mp; mp[val]=0;
        while(que.size()){
            for(auto &e:jget(que.front())){ // 找邻居
                if(mp.find(e)==mp.end()){
                    que.push(e);
                    mp[e]=mp[que.front()]+1;
                    if(e==123450) return mp[e];
                }
            }
            que.pop();
        }
        return -1;
    }
};
