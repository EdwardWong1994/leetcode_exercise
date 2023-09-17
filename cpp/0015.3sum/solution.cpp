// Created by EdwardWong1994 at 2023/09/10 14:31
// leetgo: 1.3.8
// https://leetcode.cn/problems/3sum/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         std::unordered_map<int,vector<int>>  mmap;   //key存放加数和，value存放索引
//         vector<vector<int>> result;
//         for(int i=0;i<nums.size();++i){
//             //需要对i去重
//             if(i>=1 && nums[i]==nums[i-1])  continue;
//             for(int j=i+1;j<nums.size();++j){
//                 if(j>=i+2 && nums[j]==nums[j-1]) continue;
//                 mmap.insert(pair<int,vector<int>>(nums[i]+nums[j],{i,j}));
//                 for(int z=j+1;z<nums.size();++z){
//                     auto it=mmap.find(-nums[z]);
//                     if(it!=mmap.end()){
//                         result.push_back({nums[(it->second)[0]],nums[(it->second)[1]],nums[z]});
//                         mmap.erase(it);
//                         // it=mmap.find(-nums[z]);
//                     }
//                 }
//             }
//         }
//         return result;
//     } 
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            if (i >= 1 && nums[i] == nums[i - 1]) { //三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j >i + 2  && nums[j] == nums[j-1]){   //这个地方为什么是j>i+2而不能是j>=i+2
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// 三元组元素c去重
                } else {
                    set.insert(nums[j]);
                }
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

    Solution *obj = new Solution();
    auto res = obj->threeSum(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
