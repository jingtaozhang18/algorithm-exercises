// https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 struct state {
     int row, col, val;
     state(int row, int col):row(row),col(col){}
     bool operator<(const state& other) const{
         if(col==other.col) {
            if(row==other.row){
                return val<other.val;
            }
            return row<other.row;
         }
         return col<other.col;
     }
 };

class Solution {
public:
    vector<state> vec;
    void preVisit(TreeNode* root, state& sta){
        if(!root) return;
        sta.val = root->val;
        vec.push_back(sta);
        sta.row++;
        sta.col--;
        preVisit(root->left, sta);
        sta.col+=2;
        preVisit(root->right, sta);
        sta.col--;
        sta.row--;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        state sta(0,0);
        preVisit(root, sta);
        sort(vec.begin(), vec.end());
        vector<vector<int>> ans;
        vector<int> cols;
        int preCol=INT_MIN, i;
        for(i=0;i<vec.size();++i){
            if(vec[i].col!=preCol){
                if(preCol!=INT_MIN){
                    ans.push_back(cols);
                    cols.clear();
                }
                preCol=vec[i].col;
            }
            cols.push_back(vec[i].val);
        }
        if(cols.size()) ans.push_back(cols);
        return ans;
    }
};