
// Created by Edward at 2023/08/29 16:05
// leetgo: 1.3.7
// https://leetcode.cn/problems/binary-search/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;


//使用左闭右闭区间的方式来寻找指定元素

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        //使用二分法搜索一个有序数组中的元素
//        int left = 0;
//        int right = nums.size()-1;
//        while (left<=right) {
//            int mid = left+((right-left)>>1);
//            if (nums[mid]<target) {
//                left=mid+1;
//            }else if(nums[mid]>target){
//                right=mid-1;
//            }else {
//                return mid;
//            }
//        }
//        return -1;
//    }
//};
//
//@lc code=begin
class Solution {
public:
int search(vector<int>& nums, int target){
    //使用前闭后开的方式查询
    int left=0;
    int right = nums.size();   //因为是前闭后开区间，所以这个地方应该是nums.size()
    while (left<right) {
        int mid = left+((right-left)>>1);
            if (nums[mid]<target) {
                left=mid+1; 
            }else if (nums[mid]>target) {
                right=mid;  //注意这个地方需要是mid，而不是mid-1
            }else {
                return mid;               
            }
        }
            return -1;
    }

};
//@lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();
    auto res = obj->search(nums, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
