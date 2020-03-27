#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>&nums){
    if(nums.size()==0) return 0;
    int maxV = nums[0], minV = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int temp = maxV;
        maxV = max(max(maxV * nums[i], minV * nums[i]), nums[i]);
        minV = min(min(temp * nums[i], minV * nums[i]), nums[i]);
        if (maxV > result) {
            result = maxV;
        }
    }
    return result;
}

int main(void){
    int size;
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;++i)cin>>nums[i];
    cout<<maxProduct(nums);
    return 0;
}