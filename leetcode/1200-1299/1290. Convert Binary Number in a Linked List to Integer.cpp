// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        unsigned int ans=0;
        while(head){
            ans=ans<<1;
            if(head->val==1) ans+=1;
            head=head->next;
        }
        return ans;
    }
};