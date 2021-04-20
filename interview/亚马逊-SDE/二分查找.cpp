#include<vector>
using namespace std;

int find(vector<int>& arr, int tar){
    int left=0, right=arr.size()-1, mid;
    while(left<=right){
        mid=left+(right-left)/2;
        if(arr[mid]==tar) return mid;
        else if(arr[mid]<tar) left=mid+1;
        else right=mid-1;
    }
    return -1;
}