// https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
#include<bits/stdc++.h>
using namespace std;

// 并查集特殊模板2
class UnionFind{
    // 本题因为是按行列进行查找，优化可以直接采用哈希表
public:
    // 哈希表映射关系[key,parent]
    unordered_map<int,int> parent;
    // 总共有多少不连通的并查集
    int count = 0;
    // 并查集查找首领节点操作
    int Find(int index){
        // 一开始构建并查集时候，假如key值不在并查集中则构建哈希表映射，count++
        if(parent.find(index) == parent.end()){
            parent[index] = index;
            count++;
        }
        // 查找并查集的首领节点并优化
        if(parent[index] != index)
            parent[index] = Find(parent[index]);
        return parent[index];
    }
    // 并查集合并操作
    void Uniod(int index1,int index2){
        int parent1 = Find(index1);
        int parent2 = Find(index2);
        // *这步骤很重要，直接把两节点首领一样的结果返回过滤，否则会让count多减1*
        if(parent1 == parent2)
            return;
        parent[parent1] = parent2;
        count--;
    }
};
class Solution {
public:
    // 思路：将石头行列的数值构建并查集，因此行或列需要加10001区分开
    // 合并的意思所有横坐标为 x 的石头和所有纵坐标为 y 的石头都属于同一个并查集
    // 最后返回石头数量 - 并查集的数量，就是题目要求的最多
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for(auto& stone:stones){
            uf.Uniod(stone[0] + 10001,stone[1]);
        }
        return stones.size() - uf.count;
    }
};