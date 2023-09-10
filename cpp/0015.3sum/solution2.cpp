// Created by EdwardWong1994 at 2023/09/10 14:31
// leetgo: 1.3.8
// https://leetcode.cn/problems/3sum/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        std::unordered_map<int,vector<int>>  mmap;   //key存放加数和，value存放索引
        vector<vector<int>> result;
        for(int i=0;i<nums.size();++i){
            //需要对i去重
            if(i>=1 && nums[i-1]==nums[i])  continue;
            for(int j=i+1;j<nums.size();++j){
                if(j>=i+2 && nums[j]==nums[j-1]) continue;
                mmap.insert(pair<int,vector<int>>(nums[i]+nums[j],{i,j}));
                for(int z=j+1;z<nums.size();++z){
                    auto it=mmap.find(-nums[z]);
                    if(it!=mmap.end()){
                        result.push_back({nums[(it->second)[0]],nums[(it->second)[1]],nums[z]});
                        // mmap.erase(it);
                        // it=mmap.find(-nums[z]);
                    }
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
