// https://leetcode-cn.com/problems/smallest-k-lcci/
#include<bits/stdc++.h>
using namespace std;

// 保持堆的大小不超过k
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, less<int>> que;
        for(auto e:arr){
            que.push(e);
            if(que.size()>k) que.pop();
        }
        while(!que.empty()) {
            ans.push_back(que.top());
            que.pop();
        }
        return ans;
    }
};

// 先建堆，取k个最小数字
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> que(arr.begin(), arr.end());
        while(k--&&que.empty()==false) {ans.push_back(que.top()); que.pop();}
        return ans;
    }
};

// 原地堆排
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        int i, j, f, cl, cr, size=arr.size();
        bool flag;
        for(i=(size-1)>>1;i>=0;--i){ // 从下向上遍历所有的非叶子结点
            j=i, flag=true; // 初始化指针
            while(flag){ // 理顺该节点向下的大小关系
                cl=(j<<1)+1, cr=(j<<1)+2, flag=false;
                if(cl>=size);
                else if(cr>=size){
                    if(arr[cl]<arr[j]){
                        swap(arr[cl], arr[j]);
                        j=cl, flag=true;
                    }
                }else{
                    if(arr[cr]<arr[cl]) cl=cr;
                    if(arr[cl]<arr[j]){
                        swap(arr[cl], arr[j]);
                        j=cl, flag=true;
                    }
                }
            }
        }
        while(k--){
            ans.push_back(arr[0]);
            swap(arr[0], arr[size-1]);
            --size;
            j=0, flag=true;
            while(flag){
                cl=(j<<1)+1, cr=(j<<1)+2, flag=false; // 初始化指针
                if(cl>=size);
                else if(cr>=size){
                    if(arr[cl]<arr[j]){
                        swap(arr[cl], arr[j]);
                        j=cl, flag=true;
                    }
                }else{
                    if(arr[cr]<arr[cl]) cl=cr;
                    if(arr[cl]<arr[j]){
                        swap(arr[cl], arr[j]);
                        j=cl, flag=true;
                    }
                }
            }
        }
        return ans;
    }
};

// make_heap
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        make_heap(arr.begin(), arr.end());
        k=arr.size()-k;
        while(k--) {pop_heap(arr.begin(), arr.end()); arr.pop_back();}
        return arr;
    }
};

// heap 
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int i, size=arr.size();
        make_heap(arr.begin(), arr.begin()+k, less<int>());
        for(i=size-1;i>=k;--i){
            push_heap(arr.begin(), arr.begin()+k+1, less<int>());
            pop_heap(arr.begin(), arr.begin()+k+1, less<int>());
            swap(arr[k], arr[i]);
            arr.pop_back();
        }
        return arr;
    }
};

// 保持堆大小不超过k       通过	   36 ms   18.3 MB	C++
// 先建堆再取k个最小数字	通过	48 ms	18.7 MB C++
// 原地堆排               通过	  40 ms	  18 MB   C++
// make_heap            通过	40 ms	17.6 MB  C++
// make_small_heap      通过	28 ms	17.6 MB  C++