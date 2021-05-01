// https://leetcode-cn.com/problems/employee-importance/
#include<bits/stdc++.h>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int acc=0, k;
        unordered_map<int, Employee*> mp;
        queue<int> que;
        for(auto &e: employees) mp[e->id]=e;
        if(mp.find(id)==mp.end()) return 0;
        que.push(id);
        while(que.size()){
            k=que.front(); que.pop();
            acc+=mp[k]->importance;
            for(auto &e:mp[k]->subordinates) que.push(e);
        }
        return acc;
    }
};