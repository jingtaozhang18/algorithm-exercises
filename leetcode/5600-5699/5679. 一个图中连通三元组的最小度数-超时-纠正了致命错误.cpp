// https://leetcode-cn.com/contest/weekly-contest-228/problems/minimum-degree-of-a-connected-trio-in-a-graph/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX, x, a, b, y, z;
        unordered_map<int, unordered_set<int>> map;
        unordered_map<int, int> degree;
        for(auto e:edges){
            map[min(e[0], e[1])].insert(max(e[0], e[1])); // 小边指向大边
            degree[e[0]]++, degree[e[1]]++;
        }
        unordered_map<int, unordered_set<int>>::iterator p;
        unordered_set<int>::iterator t, k;
        for(p=map.begin();p!=map.end();++p) {
            a=degree[p->first];
            for(t=p->second.begin(); t!=p->second.end();++t){
                b=degree[*t];
                for(k=t,++k; k!=p->second.end();++k){
                    y=min(*k, *t), z=max(*k, *t);
                    // 必须确定map中有y才可以，直接使用[]获取，有可能产生插入操作，造成迭代器失效
                    if(map.find(y)!=map.end()&&map[y].find(z)!=map[y].end()){ // 三元组
                        x=a+b+degree[*k]-6;
                        ans=min(ans, x);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

// 15
// [[6,15],[14,4],[3,1],[4,12],[5,7],[5,13],[4,15],[3,13],[10,6],[9,8],[8,6],[10,3],[13,2],[9,11],[8,12],[11,14],[10,12],[13,11],[15,2],[10,9],[2,14],[13,8],[1,6],[1,9],[6,14],[12,9],[3,9],[5,9],[14,15],[11,4],[5,12],[9,4],[2,4],[11,10],[13,1],[10,14],[10,8],[13,7],[2,7],[13,10],[15,10],[6,7],[6,13],[7,12],[12,2],[12,11],[4,1],[3,5],[5,2],[14,8],[5,8],[10,1],[10,7],[9,15],[11,6],[15,12],[7,8],[7,14]]
// 输出：18
// 预期结果：14