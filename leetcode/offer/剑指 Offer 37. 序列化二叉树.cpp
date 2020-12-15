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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> que;
        TreeNode*t;
        if(root) que.push(root);
        else return ans;
        while(!que.empty()){
            t=que.front(); que.pop();
            if(t){
                ans.append(to_string(t->val)+",");
                que.push(t->left);
                que.push(t->right);
            }else{
                ans.append("n,");
            }
        }
        return ans;
    }
    TreeNode* read_node(string& s, int& i){
        int ans=0, mul=1;
        if(s[i]=='n') {i+=2; return nullptr;}
        if(s[i]=='-') mul=-1,i++;
        while(s[i]!=','){
            ans*=10,ans+=(s[i]-'0');
            i++;
        }
        ans*=mul;
        i++;
        TreeNode* t=new TreeNode(ans);
        return t;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        int i=0;
        queue<TreeNode*> que;
        TreeNode*head,*l,*r,*fa=nullptr;
        head=read_node(data,i);
        que.push(head);
        while(!que.empty()){
            fa=que.front(); que.pop();
            l=read_node(data,i);
            r=read_node(data,i);
            fa->left=l, fa->right=r;
            if(l) que.push(l);
            if(r) que.push(r);
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));