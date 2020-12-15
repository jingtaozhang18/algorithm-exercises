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