// https://leetcode-cn.com/problems/list-of-depth-lcci/
#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
      vector<ListNode*> ans;
      ListNode* tail;
      if(!tree) return ans;
      int nown=1, nextn=0;
      bool newl=true;
      queue<TreeNode*> que;
      que.push(tree);
      while(!que.empty())
      {
        TreeNode* t=que.front();
        que.pop();
        if(newl)
        {
          tail=new ListNode(t->val);
          ans.push_back(tail);
          newl=false;
        }else
        {
          tail->next=new ListNode(t->val);
          tail=tail->next;
        }
        if(t->left) 
        {
          que.push(t->left);
          nextn++;
        }
        if(t->right)
        {
          que.push(t->right);
          nextn++;
        }
        if(!--nown)
        {
          nown=nextn, nextn=0, newl=true;
        }
      }
      return ans;
    }
};