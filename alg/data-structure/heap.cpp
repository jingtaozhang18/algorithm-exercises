#include <bits/stdc++.h>
using namespace std;

template<class T>
class Heap {
private:
  vector<T> arr;
  void heapify(int index) {
    while (true) {
      int max_pos = index;
      if (index * 2 < arr.size() && arr[max_pos] < arr[index * 2]) {
        max_pos = index * 2;
      }
      if (index * 2 + 1 < arr.size() && arr[max_pos] < arr[index * 2 + 1]) {
        max_pos = index * 2 + 1;
      }
      if (index == max_pos)
        break;
      swap(arr[index], arr[max_pos]);
      index = max_pos;
    }
  }

public:
  Heap(vector<T> arr) {
    this->arr = arr;
    int i;
    for (i = this->arr.size() / 2; i >= 0; --i) {
      heapify(i);
    }
  }
  void push(T val) {
    arr.push_back(val);
    int i = arr.size() - 1;
    while (i > 0) {
      if (arr[i] > arr[i / 2]) {
        swap(arr[i], arr[i / 2]);
        i = i / 2;
      }
      else {
        break;
      }
    }
  }
  T top() {
    return *arr.begin();
  }
  void pop() {
    swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    heapify(0);
  }
  size_t size() {
    return arr.size();
  }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("case", "r", stdin);
  int x;
  vector<int> input;
  while (cin >> x) {
    input.push_back(x);
  }
  Heap<int> heap(input);
  heap.push(200);
  heap.push(100);
  heap.push(0);
  while (heap.size()) {
    cout << heap.top() << " ";
    heap.pop();
  }
}
