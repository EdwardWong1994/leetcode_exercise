1.  题目要求答案中不可以包含重复的三元组，对于`[-1,1,0]`和`[-1,0,1]`是同一个三元组，输出的答案中不应该包含这个。

如何操作？

```

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
std::multimap<int,vector<int>>  mmap;   //key存放加数和，value存放索引
vector<vector<int>> result;
for(int i=0;i<nums.size();++i){
for(int j=0;j<nums.size();++j){
if(i==j) continue;
mmap.insert(pair<int,vector<int>>(nums[i]+nums[j],{i,j}));
}
}  //填充multimap容器
for(int i=0;i<nums.size();++i){
auto it=mmap.find(-nums[i]);
while(it!=mmap.end()){
if(i!=(it->second)[0] ||  i!=(it->second)[1]){   //判断i是否等于j/k
result.push_back({nums[i],nums[(it->second)[0]], nums[(it->second)[1]]}); 
}
mmap.erase(it);
it=mmap.find(-nums[i]);
}
}
return result;
}
};


```

上述代码是第一次尝试，看似没错，但是没有办法做到去重。后对`i`,`j`,`z`的索引进行了修改，依旧还是不能完全解决问题。

```

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
std::multimap<int,vector<int>>  mmap;   //key存放加数和，value存放索引
vector<vector<int>> result;
for(int i=0;i<nums.size();++i){
for(int j=i+1;j<nums.size();++j){
mmap.insert(pair<int,vector<int>>(nums[i]+nums[j],{i,j}));
for(int z=j+1;z<nums.size();++z){
auto it=mmap.find(-nums[z]);
while(it!=mmap.end()){
result.push_back({nums[z],nums[(it->second)[0]], nums[(it->second)[1]]}); 
mmap.erase(it);
it=mmap.find(-nums[z]);
}
}
}
}
return result;
} 
};

```
