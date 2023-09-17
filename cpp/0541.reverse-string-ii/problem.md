##  关于`reverse()`函数的使用

`std::reverse()`函数接受两个迭代器作为参数，表示要翻转的范围，对于字符串，可以使用`str.begin()`和`str.end()`来表示整个字符串的范围。

```
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::string str = "Hello, World!";
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::reverse(vec.begin(), vec.end());
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

```
