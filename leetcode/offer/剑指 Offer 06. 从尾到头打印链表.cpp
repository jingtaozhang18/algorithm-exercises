// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> sta;
        while(head){
            sta.push(head->val);
            head=head->next;
        }
        vector<int> ans(sta.size());
        int i=0;
        while(!sta.empty()){
            ans[i++]=sta.top();
            sta.pop();
        }
        return ans;
    }
};

// 复习
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while(head) {
            ans.push_back(head->val); 
            head=head->next;
        }
        int i=0, j=ans.size()-1;
        while(i<j) swap(ans[i++], ans[j--]);
        return ans;
    }
};

// 递归
class Solution {
public:
    void jgo(ListNode *head, vector<int>&ans){
        if(!head) return;
        jgo(head->next, ans);
        ans.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        jgo(head, ans);
        return ans;
    }
};