// https://leetcode-cn.com/problems/english-int-lcci/
#include<bits/stdc++.h>
using namespace std;

// 过程暂存
class Solution {
public:
    string jgo(vector<int>& arr){
        unordered_map<int, string> map;
        map[0]="Zero", map[1]="One", map[2]="Two", 
        map[3]="Three", map[4]="Four", 
        map[5]="Five", map[6]="Six", map[7]="Seven", 
        map[8]="Eight", map[9]="Nine",
        map[10]="Ten", map[11]="Eleven",map[12]="Twelve";
        map[13]="Thirteen", map[14]="Fourteen",
        map[15]="Fifteen", map[16]="Sixteen",map[17]="Seventeen";
        map[18]="Eighteen", map[19]="Nineteen";
        map[20]="Twenty", map[30]="Thirty",map[40]="Forty";
        map[50]="Fifty", map[60]="Sixty";
        map[70]="Seventy", map[80]="Eighty",map[90]="Ninety";
        string ans="";
        if(arr[0]>0) ans=ans+map[arr[0]] + " Hundred";
        if(arr[1]>=2) {
            ans=ans+(ans.size()?" ":"")+map[arr[1]*10];
            if(arr[2]) ans=ans+" "+map[arr[2]];
        }
        else if(arr[1]==0) {
            if(arr[2]) ans=ans+(ans.size()?" ":"")+map[arr[2]];
        }else {
            ans=ans+(ans.size()?" ":"")+map[arr[1]*10+arr[2]];
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        bool neg=num<0;
        vector<vector<int>> arr;
        int i=0;
        num=(neg?-1:1)*num;
        while(num){
            if(i%3==0) arr.push_back(vector<int>(3));
            arr[i/3][2-i%3]=num%10;
            num/=10;
            ++i;
        }
        string ans="",t;
        unordered_map<int, string> map_pos;
        map_pos[0]="", map_pos[1]=" Thousand", map_pos[2]=" Million", map_pos[3]=" Billion";
        for(i=arr.size()-1;i>=0;--i){
            t=jgo(arr[i]);
            if(t.size()) {
                if(i<arr.size()-1) ans+=" ";
                ans=ans+t+map_pos[i];
            }
            
        }
        return neg?("Negative "+ans):ans;
    }
};