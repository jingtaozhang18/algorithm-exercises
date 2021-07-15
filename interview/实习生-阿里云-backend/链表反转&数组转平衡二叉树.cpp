#include<bits/stdc++.h>
using namespace std;

//评测题目: 无
//1. 链表反转  1-2-3  -> 3-2-1

struct node{
  int val;
  node* next;
};

node* func(node* root){
  node *a=nullptr, *b=root, *c;
  while(b){
    c=b->next;
    b->next=a;
    a=b, b=c;
  }
  return a;
}


//2. 给定一个数组，转换成平衡二叉树

struct treeNode{
  int val;
  treeNode *left, * right;
  treeNode(int v):val(v), left(nullptr), right(nullptr){};
};

treeNode* func(vector<int>& arr, int left, int right){
  if(left>right) return nullptr;
  int mid=left+(right-left)/2;
  treeNode *root=new treeNode(arr[mid]);
  root->left=func(arr, left, mid-1);
  root->right=func(arr, mid+1, right);
  return root;
}

treeNode* func_enter(vector<int>& arr){
  sort(arr.begin(), arr.end());
  return func(arr, 0, arr.size()-1);
}
