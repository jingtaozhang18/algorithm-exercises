// 生产者消费者模型
#include"02-semaphore.hpp"
#include<queue>
#include<thread>
#include<iostream>
using namespace std;

class ProCon{
	int count;
	queue<int> que;
	semaphore emptyBuffers, fullBuffers; // 空位和有数据位
	mutex mtx;
	public:
		ProCon(int size = 1):emptyBuffers(size), fullBuffers(0), count(size){}
		void push(int val){
			emptyBuffers.wait(); // 占用一个空位资源
			mtx.lock();
			que.push(val);
			cout<<"after push: queue's size: "<<que.size()<<endl;
			mtx.unlock();
			fullBuffers.signal(); // 生产一个可用资源
		}
		int pop(){
			fullBuffers.wait(); // 占用一个有数据资源
			mtx.lock();
			int ans = que.front();
			que.pop();
			mtx.unlock();
			emptyBuffers.signal();
			return ans;
		}
};