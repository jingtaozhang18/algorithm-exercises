// 信号量模型
#include<mutex>
#include<condition_variable>
using namespace std;

#ifndef _jingtao_semaphore
class semaphore{
	private:		
		int count;
		mutex mtk;
		condition_variable cv;
	public:
		semaphore(int val=1):count(val){}
		void wait(){
			unique_lock<mutex> lck(mtk);
			if(--count<0) cv.wait(lck);
		}
		void signal(){
			unique_lock<mutex> lck(mtk);
			if(++count<=0) cv.notify_one();
		}
};
#endif