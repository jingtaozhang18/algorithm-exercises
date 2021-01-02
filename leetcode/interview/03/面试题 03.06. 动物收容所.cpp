// https://leetcode-cn.com/problems/animal-shelter-lcci/
#include<bits/stdc++.h>
using namespace std;

class AnimalShelf {
public:
    queue<int> qued;
    queue<int> quec;
    queue<int> quea;
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if(animal[1]) qued.push(animal[0]);
        else quec.push(animal[0]);
        quea.push(animal[0]);
    }
    
    vector<int> dequeueAny() {
        while(!quea.empty()&&quea.front()!=quec.front()&&quea.front()!=qued.front()) quea.pop();
        if(quea.empty()) return vector<int>{-1, -1};
        int id=quea.front();
        quea.pop();
        int type;
        if(id==quec.front()) {type=0; quec.pop();}
        else {type=1; qued.pop();}
        return vector<int>{id, type};
    }
    
    vector<int> dequeueDog() {
        if(qued.empty()) return vector<int>{-1,-1};
        int id=qued.front();
        qued.pop();
        return vector<int>{id, 1};
    }
    
    vector<int> dequeueCat() {
        if(quec.empty()) return vector<int>{-1,-1};
        int id=quec.front();
        quec.pop();
        return vector<int>{id, 0};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */