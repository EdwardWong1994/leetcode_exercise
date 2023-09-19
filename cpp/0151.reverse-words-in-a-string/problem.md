## `string`表示的是一个字符序列，，而不是以`\0`结尾的`C`风格的字符串

`std::string`对象的最后一个字符并不是`\0`,  然而`std::string`类提供了一个成员函数`c_str()`,该函数返回一个以`\0`结尾的`c`风格字符串，这是为了与`C`代码进行兼容

## `C++  string`类中的`size`函数返回的是字符串中字符的数量，不包含`\0`字符


## 如何移除字符串中特定的元素？？

可以使用`erase`函数移除字符串中的元素

1. 删除指定位置的字符

```
#include <iostream>
#include <string>

int main() {
std::string s = "Hello, World!";

// 删除位置为5的字符，即','，结果为 "Hello World!"
s.erase(s.begin() + 5);

std::cout << s << std::endl;

return 0;
}

```


2. 删除指定区间的字符

```
string str = "Hello, World!";
str.erase(3, 5); // 从位置3开始删除5个字符

```


3. 删除指定迭代器范围内的字符

```
string str = "Hello, World!";
auto iter1 = str.begin() + 3;
auto iter2 = str.begin() + 8;
str.erase(iter1, iter2); // 删除[iter1, iter2)范围内的字符

```


##  在使用库函数`erase`函数时需要知道`erase()`函数的时间复杂度是`o(n)`

##  这道题可以使用双指针的思路移除空格

在使用双指针解答问题的时候，一直出现一个`case`通过不了的情况，“  hello  world  ” -->  返回结果是` world hello`

`if(right==s.size()-1  &&  s[right]==' ')  break;`


