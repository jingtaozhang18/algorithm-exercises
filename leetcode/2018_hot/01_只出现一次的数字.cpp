#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (int n : nums){
            ans ^= n;
        }
        return ans;
    }
};

int main(){
    cout << "size of int" << sizeof(int) << endl;
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}


