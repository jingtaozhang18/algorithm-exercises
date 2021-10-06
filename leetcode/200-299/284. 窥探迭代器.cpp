// https://leetcode-cn.com/submissions/detail/225982046/
#include <bits/stdc++.h>
using namespace std;

//  Below is the interface for Iterator, which is already defined for you.
//  **DO NOT** modify the interface for Iterator.

class Iterator {
  struct Data;
  Data* data;

 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    flagHasNext = Iterator::hasNext();
    if (flagHasNext) {
      nextElement = Iterator::next();
    }
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() { return nextElement; }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    int ret = nextElement;
    flagHasNext = Iterator::hasNext();
    if (flagHasNext) {
      nextElement = Iterator::next();
    }
    return ret;
  }

  bool hasNext() const { return flagHasNext; }

 private:
  int nextElement;
  bool flagHasNext;
};
