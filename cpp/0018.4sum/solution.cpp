// Created by EdwardWong1994 at 2023/09/10 20:28
// leetgo: 1.3.8
// https://leetcode.cn/problems/4sum/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //使用双指针解答问题
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();++i){
            if(nums[i]>target && target>=0) break;  //只有正数的时候才满足条件
            //去重操作
            if(i>0 && nums[i]==nums[i-1])  continue;
            for(int j=i+1;j<nums.size();++j){
                //剪枝操作
                if((long)(nums[i]+nums[j])>target && target>=0) break;
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1; 
                int right=nums.size()-1;
                while(left<right){
                    if((long)nums[i]+(long)nums[j]+(long)nums[left]+(long)nums[right]>target) {
                        right--;
                    }else if((long)nums[i]+(long)nums[j]+(long)nums[left]+(long)nums[right]<target){
                        left++;   
                    } else{
                        results.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(left<right  && nums[left]==nums[left+1])  left++;   
                        while( left<right  && nums[right]==nums[right-1])right--;   
                        left++;
                        right--;
                    } 
                }
            }
        }
        return  results;
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
    auto res = obj->fourSum(nums, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
