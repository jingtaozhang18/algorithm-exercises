// 生产者消费者模型
#include"02-semaphore.cpp"
#include<queue>
using namespace std;

class ProCon{
	int count;
	queue<int> que;
	semaphore s;
	mutex mtx;
	public:
		ProCon(int size = 1):s(size), count(size){}
		void push(int val){
			s.wait(); // 占用一个资源
			mtx.lock();
			que.push(val);
			mtx.unlock();
		}
		int pop(){
			s.signal(); // 空出一个资源
			mtx.lock();
			int ans = que.front();
			que.pop();
			mtx.unlock();
			return ans;
		}
};
