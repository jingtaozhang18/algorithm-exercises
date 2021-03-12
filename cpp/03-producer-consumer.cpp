// 生产者消费者模型测试
// g++ -pthread -o main 03-producer-consumer.cpp  && ./main
#include"03-producer-consumer.hpp"
#include<iostream>
using namespace std;

ProCon que(2);

void producer(){
	int times=10, val=1;
	while(times--) que.push(val++);
}

void consumer(){
	int times=10;
	while(times--) {
		int val = que.pop();
		cout<<"read num: "<<val<<endl;
	}
}

int main(void){
	thread p(producer);
	thread c(consumer);
	p.join();
	c.join();
	return 0;
}