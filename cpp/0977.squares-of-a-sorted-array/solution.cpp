// Created by EdwardWong1994 at 2023/08/30 19:25
// leetgo: 1.3.7
// https://leetcode.cn/problems/squares-of-a-sorted-array/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
#include <vector>
using namespace std;

// @lc code=begin
// 第一种解法对不同情况做了判断，但是实际情况根本不需要分类讨论，直接使用双指针的思想就可以 
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        //采用双指针的解答方法
//        int size =nums.size();
//        int start = 0;
//        int end =size-1; 
//        vector<int> res(size);
//        //case 1:  所有元素都为正数
//        if (nums[start]>=0) {
//            for (size_t start = 0; start <=size-1; start++) {
//                res[start]=nums[start]*nums[start];
//            }
//            return res;
//        }  
//        if (nums[end]<=0) {
//            //case 2:  第一个元素为负的，且最后一个元素也为负
//            for (size_t start = 0; start <=size-1; start++) {
//                res[end]=nums[start]*nums[start];
//                end--;
//            } 
//            return res;
//        } 
//        int loc=end;
//        if(nums[start]<0 & nums[end]>0){
//            //case 3 ： 第一个元素为负数，最后一个元素为正数 
//            while(start<=end) {
//                if (nums[start]*nums[start]<=nums[end]*nums[end]) {
//                    res[loc--]=nums[end]*nums[end];
//                    end--;
//                }else {
//                    res[loc--]=nums[start]*nums[start];
//                    start++;
//                }
//            }
//        return res; 
//        }
//    }
//};

class Solution{
public:
    vector<int> sortedSquares(vector<int> & nums){
        int size=nums.size();
        int start=0;
        int end =size-1;
        int loc=end;
        vector<int> res(size);
        while(start<=end){
            if (nums[start]*nums[start]<=nums[end]*nums[end]) {
                res[loc--]=nums[end]*nums[end];
                end--;
            }else {
                res[loc--]=nums[start]*nums[start];
                start++;                
            }
        }
        return res;
    }

};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->sortedSquares(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
