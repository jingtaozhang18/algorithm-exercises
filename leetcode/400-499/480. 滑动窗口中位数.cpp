// https://leetcode-cn.com/problems/sliding-window-median/
#include<bits/stdc++.h>
using namespace std;

class mid{
public:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    multiset<int> nosense;
    int nosense_left, nosense_right;
    mid():nosense_left(0),nosense_right(0){};
    void push(int val){
        if(left.size()-nosense_left==right.size()-nosense_right){ // push left
            left.push(val);
            if(!right.empty()&&left.top()>right.top()) {
                int a=left.top(), b=right.top();
                left.pop(); left.push(b);
                right.pop(); right.push(a);
            }
        }else{ // push right
            right.push(val);
            if(left.top()>right.top()) {
                int a=left.top(), b=right.top();
                left.pop(); left.push(b);
                right.pop(); right.push(a);
            }
        }
        adjust(); // 错误点: push操作也会暴露出新的已有元素,可能是需要删除的元素,因此也需要adjust调整
    }
    double get_mid(){
        if(left.size()-nosense_left==right.size()-nosense_right) return ((double)left.top()+right.top())/2;
        else return left.top();
    }
    void pop(int val){
        if(val<=left.top()) nosense_left++;
        else nosense_right++;
        nosense.insert(val);
        adjust();
    }
    void adjust(){
        bool flag=true;
        while(flag){
            flag=false;
            multiset<int>::iterator p;
            if(left.size()&&(p=nosense.find(left.top()))!=nosense.end()){
                left.pop(); 
                nosense_left--;
                nosense.erase(p);
                flag=true;
            }
            if(right.size()&&(p=nosense.find(right.top()))!=nosense.end()){
                right.pop();
                nosense_right--;
                nosense.erase(p);
                flag=true;
            }
            if(left.size()-nosense_left<right.size()-nosense_right){
                left.push(right.top());
                right.pop();
                flag=true;
            }
            if(left.size()-nosense_left>right.size()-nosense_right+1){
                right.push(left.top());
                left.pop();
                flag=true;
            }
        }    
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        mid jm;
        vector<double> ans;
        int i, size=nums.size();
        for(i=0;i<size;++i){
            jm.push(nums[i]);
            if(i>=k-1){
                ans.push_back(jm.get_mid());
                jm.pop(nums[i-k+1]);
            }
        }
        return ans;
    }
};