// https://leetcode-cn.com/problems/design-bounded-blocking-queue/
#include<bits/stdc++.h>
using namespace std;

class BoundedBlockingQueue {
    list<int> msgs;
    int cap;
    std::mutex my_mutex;
	std::condition_variable my_cond;
public:
    BoundedBlockingQueue(int capacity):cap(capacity){
        
    }

    bool isFull(){
        return msgs.size() == cap;
    }

    bool isEmpty(){
        return msgs.size() == 0;
    }
    
    void enqueue(int element) {
        std::unique_lock<std::mutex> locker(my_mutex);
        my_cond.wait(locker,[this]{
            return !isFull();
        });
        msgs.push_back(element);
        my_cond.notify_all();
    }
    
    int dequeue() {
        std::unique_lock<std::mutex> locker(my_mutex);
        my_cond.wait(locker,[this]{
            return !isEmpty();
        });
        int ret = msgs.front();
        msgs.pop_front();
        my_cond.notify_all();
        return ret;
    }
    
    int size() {
        return msgs.size();
    }
};

// 作者：fred-a
// 链接：https://leetcode-cn.com/problems/design-bounded-blocking-queue/solution/yong-c11de-tiao-jian-bian-liang-zui-sheng-nei-cun-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。