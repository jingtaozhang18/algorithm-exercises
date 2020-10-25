#include<stack>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sta;
        while(root||!sta.empty()){
            while(root){
                sta.push(root);
                root=root->left;
            }
            TreeNode* t=sta.top();
            sta.pop();
            if(! --k) return t->val;
            root=t->right;
        }
        return 0;
    }
};