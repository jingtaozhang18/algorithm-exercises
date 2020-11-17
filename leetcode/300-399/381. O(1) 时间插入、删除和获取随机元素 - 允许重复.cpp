// https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
#include<bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idxs; // 存储元素存在的下标
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        unordered_map<int, unordered_set<int>>::iterator p;
        bool ans=false;
        if((p=idxs.find(val))==idxs.end()) idxs[val]=unordered_set<int>(), ans=true;
        idxs[val].insert(nums.size()-1);
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        unordered_map<int, unordered_set<int>>::iterator p;
        if((p=idxs.find(val))==idxs.end()) return false;
        int i=*(p->second.begin()), t; // 要删除的元素的位置
        if(p->second.size()==1) idxs.erase(p); // 整个删除掉
        else p->second.erase(p->second.begin()); // 删除集合中的一个元素
        if(i==nums.size()-1) {nums.pop_back(); return true;}
        p=idxs.find(nums.back());
        p->second.erase(p->second.find(nums.size()-1));
        p->second.insert(i);
        nums[i]=nums.back();
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */