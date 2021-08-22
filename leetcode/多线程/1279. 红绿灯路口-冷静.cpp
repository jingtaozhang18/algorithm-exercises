// https://leetcode-cn.com/problems/traffic-light-controlled-intersection/
#include<bits/stdc++.h>
using namespace std;

class TrafficLight {
public:
    mutex lock;
    int flag;
    TrafficLight() {
        flag=1;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        int times=5;
        lock.lock();
        while(flag!=roadId&&times--){
            lock.unlock();
            lock.lock();
        }
        if(flag!=roadId){
            turnGreen();
            flag=roadId;
        }
        crossCar();
        lock.unlock();
    }
};