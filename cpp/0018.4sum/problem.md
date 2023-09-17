###  这道题nums[i]+nums[j]+nums[left]+nums[right]>target可能会越界，因此需要转为long类型，

但是奇怪的是为什么`if((long)nums[i]+nums[j]+nums[left]+nums[right]>target)`可以运行而`if((long)(nums[i]+nums[j]+nums[left]+nums[right])>target)` 不可以运行, 

其实最后这样写更安全，将`nums[i]`,`nums[j]`,`nums[left]`,`nums[right]`都转为`long`类型的

