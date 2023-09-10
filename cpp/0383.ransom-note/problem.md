1. 如何删除`multiset`中的一个元素？

可以使用`erase`方法，没有`remove`方法 

-  如果要删除所有的键

    ```

    #include <iostream>
    #include <set>

    int main()
    {
    std::multiset<int> mySet = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    // 删除所有元素3
    mySet.erase(3);

    // 删除所有键值为4的元素
    mySet.erase(4);

    // 输出剩下的元素
    for (auto it = mySet.begin(); it != mySet.end(); ++it)
    {
    std::cout << *it << " ";
    }

    return 0;
    }
    ```

- 如果只删除一个值

    如果你只想删除一个元素，你可以使用`find()`方法查找要删除的元素，然后将迭代器传递给`erase()`方法

    ```
    #include <iostream>
    #include <set>

    int main() 
    {
    std::multiset<int> mySet = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    // 删除一个元素
    auto it = mySet.find(3);
    if (it != mySet.end())
    {
    mySet.erase(it);
    }

    // 输出剩下的元素
    for (auto it = mySet.begin(); it != mySet.end(); ++it)
    {
    std::cout << *it << " ";
    }

    return 0;
    }
    ```


2.  在最初的算法思路上，采用了`multiset`容器，但是采用数组作为哈希表会比较方便，因为对于`multiset`需要维护红黑树，还要做哈希函数，不 n 如数组高效
