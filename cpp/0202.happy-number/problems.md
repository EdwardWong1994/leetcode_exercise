1. `C++`中如何求余数和除数

在`C++`中，可以使用取模运算符`%`来求余数，使用除法运算符`/`来求除数。

```
#include <iostream>

int main() {
int a = 10, b = 3;
int remainder = a % b;  // 求a除以b的余数
int quotient = a / b;   // 求a除以b的商
std::cout << "a % b = " << remainder << std::endl;
std::cout << "a / b = " << quotient << std::endl;
return 0;
}

```


2. 在解这道题的时候会想如果永远不会变为1，该怎么停止 ？

题目中的**无限循环**比较有迷惑性，指的是在不断平方的过程中会重复出现相同的值，而不是对平方的过程不断循环, 理解了这点后，就可以借助`unordered_set`容器进行解题
