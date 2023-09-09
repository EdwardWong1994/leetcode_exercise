// Created by EdwardWong1994 at 2023/09/09 20:55
// leetgo: 1.3.8
// https://leetcode.cn/problems/two-sum/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

// class Solution {
// public:
//     //本题的关键在于使用时间复杂度小于o（n^2）的算法
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_set<int> set1(nums.begin(),nums.end());
//         vector<int> result; 
//         for(int i=0; i<nums.size();++i){
//             int tmp = target-nums[i];
//             if(set1.find(tmp)!=set1.end()){
//                 for(int j=0; j<nums.size();++j){
//                     if(j==i)  break;
//                     if(nums[j]==tmp  && j!=i){  //需要注意的是数组中同一个元素在答案中不能重复出现
//                         result.push_back(i);
//                         result.push_back(j);
//                         break;
//                     };
//                 }          
//
//             }
//         } 
//         return result;
//     }
// };

class  Solution{
public:
    //之前使用了unordered_set容器，但是使用unordered_map会更好，因为对于unordered_map而言，key存值，value存索引。 在遍历数组的时候，如果在map中存在目标值，则取出，如果不存在目标值，则将当前的值加入map中
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int,int> map1;
        vector<int> result;
        for(int i=0;i<nums.size();++i){
            int tmp = target-nums[i];
            auto it =map1.find(tmp);
            if(it!=map1.end()){
                return {it->second,i};
            }else{
                map1.insert(pair<int, int>(nums[i],i)); 
            }  
        }
        return result;
    }

};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();
    auto res = obj->twoSum(nums, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
