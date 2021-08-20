// https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1664&konwledgeId=134
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  while (cin >> n) {
    int ans = 1, period = 2, acc = 0;
    --n;
    while (n >= period) {
      n -= period;
      ++period;
      ans += acc;
      ++acc;
    }
    ans += n;
    cout << ans << endl;
  }
  return 0;
}