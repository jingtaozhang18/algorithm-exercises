// https://leetcode-cn.com/explore/interview/card/top-interview-quesitons-in-2018/275/string/1138
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> mem; // 记录计算状态十分重要，因为加了此项，结果得到了通过
    bool word_p(string&s, int start, vector<string>& wordDict){
        if(start==s.length()) return true;
        bool flag[wordDict.size()];
        memset(flag, 1, sizeof(flag)); // 单词均可用
        int fin=0; // 不可使用单词数量，用于提前终止
        for(int i=0; i<s.length()-start; i++){
            for(int j=0;j<wordDict.size();j++){
                if (flag[j]==false) continue;
                if (s[i+start]==wordDict[j][i]){ // 匹配
                    if(i==wordDict[j].size()-1){ // 检查是否完全匹配
                        flag[j]=false;
                        fin++;
                        if(mem[i+start+1]!=-1 && (mem[i+start+1] || word_p(s, i+start+1, wordDict))){
                            mem[i+start+1] = 1;
                            return true; // 可行方案
                        }
                    }
                }else{
                    flag[j]=false;
                    fin++; 
                }
            }
            if(fin==wordDict.size()) break;
        }
        mem[start] = -1;
        return false; // 没有找到可行方案。
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        mem.clear();
        mem.assign(s.size(), 0);
        mem.push_back(1);
        return wordDict.size()!=0 ? word_p(s, 0, wordDict) : false;
    }
};