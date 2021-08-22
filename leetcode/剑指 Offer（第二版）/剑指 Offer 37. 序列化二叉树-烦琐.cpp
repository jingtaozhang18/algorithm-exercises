// https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int jread(string &data, int &i){
    int ans=0; bool flag=false;
    if(data[i]=='-') flag=true, ++i;
    while(data[i]>='0'&&data[i]<='9') ans*=10, ans+=data[i]-'0', ++i;
    return flag?-1*ans:ans;
}
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        stack<TreeNode*> sta;
        if(root) sta.push(root);
        while(sta.size()){
            root=sta.top();
            sta.pop();
            if(!root) {ans+='#'; continue;}
            ans+=to_string(root->val)+',';
            sta.push(root->right);
            sta.push(root->left);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root=nullptr, *t;
        if(data.size()==0) return root;
        stack<TreeNode*> sta;
        int i, val;
        bool flag=false;
        for(i=0;i<data.size();++i){
            if(data[i]=='#'){
                if(!sta.top()->left&&!flag) flag=true;
                else {
                    sta.pop(); 
                    flag=false;
                    while(sta.size()){
                        if(sta.top()->right) sta.pop();
                        else break;
                    }
                }
            }else{
                val=jread(data, i);
                if(!root){
                    root=new TreeNode(val);
                    sta.push(root);
                }else{
                    t=sta.top();
                    if(!t->left&&!flag) {
                        t->left=new TreeNode(val);
                        sta.push(t->left);
                    }else{
                        t->right=new TreeNode(val);
                        sta.push(t->right);
                        flag=false;
                    }
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));