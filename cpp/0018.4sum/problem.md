###  这道题nums[i]+nums[j]+nums[left]+nums[right]>target可能会越界，因此需要转为long类型，

但是奇怪的是为什么`if((long)nums[i]+nums[j]+nums[left]+nums[right]>target)`可以运行而`if((long)(nums[i]+nums[j]+nums[left]+nums[right])>target)` 不可以运行, 

其实最后这样写更安全，将`nums[i]`,`nums[j]`,`nums[left]`,`nums[right]`都转为`long`类型的


###  这道题与力扣454 四数之和II 的区别在于力扣454是给了四个数组，而力扣18是一个数组且要求元素不能重复，力扣18的难点在于去重
