#include<bits/stdc++.h>
using namespace std;

//评测题目: 锯齿打印二叉树
// 								a
//          b              c
//     e        f     g         h
// i      j
// acbefghji

struct TreeNode{
    char val;
    TreeNode *left, *right;
};

struct node{
    char c;
    node* next;
    node(node*n, char c):c(c),next(n){};
};

node* put(node* n, char c){
    node* head=new node(n, c);
    return head;
}

void level_print(TreeNode* root){
    int now_num, next_num;
    bool zx=true;
    // queue<node*> que; // error
    queue<TreeNode*> que;
    if(!root) return;
    que.push(root);
    now_num=1, next_num=0;
    node *head, *t;
    while(!que.empty()){
        root=que.front();
        que.pop();
        if(root->left) { que.push(root->left); next_num++; }
        if(root->right) { que.push(root->right); next_num++; }
        if(zx) cout<<root->val;
        else{
            if(head) head=put(head, root->val);
            else head=new node(nullptr, root->val);
        }
        --now_num;
        if(now_num==0){
            if(!zx){
                while(head) {
                    // cout<<head->val;
                    cout<<head->c;
                    t=head;
                    head=head->next;
                    delete t;
                }
            }
        }
        now_num=next_num, next_num=0, zx=!zx;
    }
    // } // error
    return ;
}
// 使用栈进行层次遍历
void level_print(TreeNode* root){
int now_num, next_num;
    bool zx=true;
    // stack<node*> sta_a; // error
    // stack<node*> sta_b; // error
    stack<TreeNode*> sta_a;
    stack<TreeNode*> sta_b;
    if(!root) return;
    sta_a.push(root);
    // while(!sta_a.empty())){ // error
    while(!sta_a.empty()){
        root=sta_a.top();
        sta_a.pop();
        cout<<root->val;
        if(zx){
            if(root->left) sta_b.push(root->left);
            if(root->right) sta_b.push(root->right);
        }else{
            if(root->right) sta_b.push(root->right);
            if(root->left) sta_b.push(root->left);
        }
        if(sta_a.empty()) {
            sta_a=sta_b;
            // sta_b.clear(); // 面试后，没有这个方法 error
            while (!sta_b.empty()) sta_b.pop();
            // zx=!flag; // error
            zx=!zx;
            
        }
    }
    return ;
}