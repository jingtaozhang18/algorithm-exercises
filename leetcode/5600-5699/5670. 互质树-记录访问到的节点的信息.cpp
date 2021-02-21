// https://leetcode-cn.com/problems/tree-of-coprimes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int x, int y) {return y?gcd(y, x%y):x;}
    vector<int> cd[51];
    vector<int> nums; // 数值
    vector<vector<int>> arr; // 邻接矩阵
    vector<int> ans;
    vector<int> vi;
    map<int, int> pre[51]; // 访问到的节点 map[i][key]=val; 值为i的节点层级为key，编号为val;  也可以使用栈来记录
    void dfs(int i, int l){ // 开始的节点，遍历的深度
        // 寻找互质的祖节点
        int aa=-1, ll=-1; // aa节点编号， ll节点的深度
        for(auto e:cd[nums[i]]){ // 找到和nums[i]互质的数
            if(pre[e].size()){ // 层级最高的一个
                if(pre[e].rbegin()->first>ll) aa=pre[e].rbegin()->second, ll=pre[e].rbegin()->first;
            }
        }
        ans[i]=aa;
        pre[nums[i]][l]=i; // 注册自己已经访问了
        vi[i]=1; // 已发现
        for(auto e:arr[i]){
            if(vi[e]==0){
                // 探索
                dfs(e, l+1);
            }
        }
        vi[i]=2; // 已探索
        pre[nums[i]].erase(l);
        // dfs 遍历
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums=nums;
        int i, j, size=nums.size(),x,y;
        for(i=1;i<=50;++i){
            for(j=i;j<=50;++j){
                if(gcd(i, j)==1) {
                    cd[i].push_back(j), cd[j].push_back(i);
                }
            }
        }
        arr=vector<vector<int>>(size, vector<int>());
        for(auto e:edges){
            x=e[0], y=e[1];
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        vi=vector<int>(size);
        ans=vector<int>(size);
        dfs(0, 0);
        return ans;
    }
};