
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
        vector<vector<int>>  result; 
        //使用双指针的思路来解决问题
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0) return result;
            //需要对i进行去重操作，去重之前先要进行排序
            if(i>0 && nums[i-1]==nums[i])  continue;
            //定义一个left指针从i+1开始，另一个指针从nums.size()-1开始
            int left=i+1;
            int  right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;                    
                }else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    //对left和right进行剪枝操作
                    while(left<right && nums[right]==nums[right-1])  right--;
                    while(left<right && nums[left]== nums[left+1]) left++;
                    right--;
                    left++;
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
