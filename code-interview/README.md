# 程序员代码面试指南
[牛客网在线测试](https://www.nowcoder.com/ta/programmer-code-interview-guide)

#### 常见错误整理
* 出现没有输出结果的时候，很有可能是代码超时。
* cin 输入加速
``` c++
ios_base::sync_with_stdio(false); // 比 printf的效率更高
cin.tie(0);
```