// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
 public:
  int rand10() {
    int origin = 7;
    int dr = 10;
    int total_area = origin * origin;
    int valid_area = total_area - total_area % dr;
    int x;
    while (true) {
      x = (rand7() - 1) * origin + rand7() - 1;
      if (x >= valid_area) continue;
      return x % dr + 1;
    }
    return -1;
  }
};