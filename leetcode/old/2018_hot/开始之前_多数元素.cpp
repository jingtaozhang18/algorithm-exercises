#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,ans;
        for(int each : nums){
            if (count==0){
                ans=each;
                count=1;
            }
            else if (each==ans){
                count++;
            } else{
                count--;
            }
        }
        return ans;
    }
};