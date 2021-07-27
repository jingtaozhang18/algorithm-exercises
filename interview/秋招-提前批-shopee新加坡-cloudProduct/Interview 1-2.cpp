// 子数组的最大和
#include<bits/stdc++.h>
using namespace std;

int calc(vector<int>& arr){
    if(arr.size()==0) return 0;
    int ans=arr[0], i;
    for(i=1;i<arr.size();++i){
        arr[i]=max(arr[i], arr[i]+arr[i-1]);
        ans=max(ans, arr[i]);
    }
    return ans;
}

int main(void){
    vector<int> input;
    input.push_back(1);
    input.push_back(-2);
    input.push_back(3);
    input.push_back(10);
    input.push_back(-4);
    input.push_back(7);
    input.push_back(2);
    input.push_back(-5);
    // 1 -2，3，10，-4，7，2，-5
    cout<<calc(input)<<endl;
    return 0;
}