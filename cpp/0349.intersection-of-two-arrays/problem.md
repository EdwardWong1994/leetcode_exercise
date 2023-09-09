1. 如何向无序列容器中添加元素？

可以使用`insert`方法插入，但是不能使用`push`.  `push`可以向序列型容器中插入元素。

对于`insert`函数，可以将一个元素插入到无序集合中，并返回一个`std::pair`对象，其中包含一个迭代器和一个布尔值，如果插入成功，则布尔值为`true`, 否则为`false`.

```

#include <iostream>
#include <unordered_set>

int main() {
// 定义并初始化无序集合
std::unordered_set<int> mySet = {1, 2, 3};

// 使用insert()函数向无序集合中添加元素
auto result = mySet.insert(4);

// 检查插入是否成功
if (result.second) {
std::cout << "Insertion succeeded!" << std::endl;
} else {
std::cout << "Insertion failed!" << std::endl;
}

// 遍历无序集合并输出元素
for (const auto& elem : mySet) {
std::cout << elem << std::endl;
}

return 0;
}
```

也可以使用下列公式插入或初始化`unordered_set<>`中

```
std::unordered_set<int> mySet1 = {1, 2, 3};
std::unordered_set<int> mySet2 = {4, 5, 6};
mySet1.insert(mySet2.begin(), mySet2.end());

```

`push()`方法是用于将元素添加到序列容器（如`std::vector`、`std::deque`等）的末尾，而不是用于无序容器（如`std::unordered_set`）

2. 如何判断一个元素是否在`unordered_set`中?  可以使用`find()`函数来判断，会返回一个迭代器，如果此元素存在于集合中，则返回指向该元素的迭代器，否则，返回指向集合末尾的迭代器 

```
#include <iostream>
#include <unordered_set>

int main() {
// 定义并初始化无序集合
std::unordered_set<int> mySet = {1, 2, 3};

// 使用count()函数判断元素是否存在于无序集合中
if (mySet.count(2)) {
std::cout << "Element found using count() function!" << std::endl;
} else {
std::cout << "Element not found using count() function!" << std::endl;
}

// 使用find()函数判断元素是否存在于无序集合中
auto it = mySet.find(2);
if (it != mySet.end()) {
std::cout << "Element found using find() function!" << std::endl;
} else {
std::cout << "Element not found using find() function!" << std::endl;
}

return 0;
}

```


3. 如何查找一个元素是否存在于一个容器中？

`std::find()`函数可以用于查找任何容器中的元素是否存在，只要该容器提供了迭代器。例如，可以使用`std::find()`函数来查找`std::vector`、`std::list`、`std::set`、`std::map`、`std::unordered_set`、`std::unordered_map`等容器中的元素。

`std::find()`返回的是一个迭代器

```
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myVec = {1, 2, 3, 4, 5};
    auto it = std::find(myVec.begin(), myVec.end(), 3);
    if (it != myVec.end()) {
        std::cout << "Element found in vector!" << std::endl;
    } else {
        std::cout << "Element not found in vector!" << std::endl;
    }
    return 0;
}

```

