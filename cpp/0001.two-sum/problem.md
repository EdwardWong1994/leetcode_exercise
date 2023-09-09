1. 之前使用了`unordered_set`容器，但是使用`unordered_map`会更好，因为对于`unordered_map`而言，`key`存值，`value`存索引。

在遍历数组的时候，如果在`map`中存在目标值，则取出，如果不存在目标值，则将当前的值加入`map`中

2. 如何理解`map.insert(pair<int,int>(nums[i],i))`?

这段代码是在使用`C++`中的`STL`容器`map`将一个键值对插入到`map`中。具体来说，`pair<int, int>(nums[i], i)`创建了一个类型为`pair<int, int>`的键值对，其中第一个元素为`nums[i]`，第二个元素为`i`。然后，`map.insert()`将这个键值对插入到`map`中。这样可以将一个整数数组`nums`中的元素作为键，元素下标作为值，存储到`map`中。

