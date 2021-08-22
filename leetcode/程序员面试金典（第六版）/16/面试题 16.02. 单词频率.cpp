// https://leetcode-cn.com/problems/words-frequency-lcci/
#include<bits/stdc++.h>
using namespace std;

class WordsFrequency {
public:
    unordered_map<string, int> mem;
    WordsFrequency(vector<string>& book) {
        for(auto e:book) mem[e]++;
    }
    
    int get(string word) {
        return mem[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */