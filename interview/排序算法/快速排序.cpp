#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right, int pivotIndex){
    // [left, right]区间的原地分割函数
    swap(arr[pivotIndex], arr[right]);
    int pivotValue=arr[right], i, idx=left; // idx是比pivotValue小的右不可达边界
    for(i=0;i<right;++i){ // 不需要遍历到right的位置
        if(arr[i]<pivotValue){
            swap(arr[i], arr[idx++]);
        }
    }
    swap(arr[idx], arr[right]);
    return idx;
}

void quickSort(vector<int>& arr, int left, int right){
    // 快速排序入口
    int pivotIndex=left; // 可扩展选择随机数
    int idx=partition(arr, left, right, pivotIndex);
    quickSort(arr, left, idx-1);
    quickSort(arr, idx+1, right);
}