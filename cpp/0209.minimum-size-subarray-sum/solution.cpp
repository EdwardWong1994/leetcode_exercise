// Created by EdwardWong1994 at 2023/08/30 20:42
// leetgo: 1.3.7
// https://leetcode.cn/problems/minimum-size-subarray-sum/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
#include <cstddef>
#include <cstdint>
#include <sys/_types/_size_t.h>
using namespace std;

// @lc code=begin

//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        //尝试使用暴力解法来解题
//        //使用暴力算法超时了
//        long long  size=nums.size();
//        long long  min=INT32_MAX;
//        long long sum=0;
//        for(int i=0;i<size;i++){
//            sum=0;
//            for (int j = i; i < size; ) {
//                sum+=nums[j++];
//                if(sum>=target){
//                    min = (min<=(j-i))?min:(j-i);
//                    break;
//                }
//            }
//        }
//        return min<INT32_MAX?min:0;    //还需要和0进行对比，因为有可能找不到
//    }
//};


//自己尝试写滑动窗口解法还是超出时间限制,在这段代码中我尝试使用for循环代表起始位置，终止位置使用rolling_window来代替的，这样还是双层循环。时间复杂度大于O（n）
//class Solution{
//public:
//    int minSubArrayLen(int target,vector<int> &nums){
//        //使用滑动窗口解决问题
//        int size=nums.size();
//        int rolling_window = INT32_MAX;
//        for (size_t i = 0; i <size; i++) {
//            int sum=0;
//            for (size_t j = i;  (j-i+1)<=rolling_window & j<size; j++) { //要注意j的边界不可越界
//                sum+=nums[j];
//                if (sum>=target)  {rolling_window = j-i+1; 
//                    break;}
//            }
//        }
//        return rolling_window==INT32_MAX?0:rolling_window;
//    }
//};

//既然让for循环的循环变量代表起始位置难免陷入双层循环的逻辑，那么可以使用for循环的循环变量代表结尾位置。
//那么起始位置在子数组满足大于target之后就后移

class  Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int slide_window = INT32_MAX;
        int sum=0;
        int j=0;
        int size=nums.size();
        for (size_t i = 0; i < size; i++) {
            sum+=nums[i];
            while (sum>=target) {
                sum-=nums[j++];
                slide_window=slide_window>(i-j+2)?(i-j+2):slide_window;
            }
        }
        return slide_window<INT32_MAX?slide_window:0;
    }

};


// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int target;
    LeetCodeIO::scan(cin, target);
    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->minSubArrayLen(target, nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
