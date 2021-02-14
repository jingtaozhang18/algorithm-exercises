// https://leetcode-cn.com/problems/couples-holding-hands/
#include<bits/stdc++.h>
using namespace std;

struct junion{
    int size;
    vector<int> arr;
    junion(int size):arr(vector<int>(size)), size(size){for(int i=0;i<size;++i)arr[i]=i;};
    int find(int i){if(arr[i]!=i) arr[i]=find(arr[i]); return arr[i];}
    void merge(int i, int j){
        i=find(i);
        j=find(j);
        if(i!=j) arr[i]=j;
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int i, size=row.size(), a, b, v, ans=0;
        junion jun(size/2);
        unordered_map<int, int> map;
        for(i=0;i<size;i+=2){
            a=row[i]%2?row[i]-1:row[i];
            b=row[i+1]%2?row[i+1]-1:row[i+1];
            a/=2, b/=2;
            jun.merge(a, b);
        }
        for(i=0;i<size/2;++i){
            map[jun.find(i)]++;
        }
        for(auto p:map){
            ans+=p.second-1;
        }
        return ans;
    }
};