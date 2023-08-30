 :/ Created by Edward at 2023/08/29 18:11
// leetgo: 1.3.7
// https://leetcode.cn/problems/remove-element/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;


//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //使用双指针来解决问题
//        int i=0;
//        int j=nums.size()-1;
//        while (i<=j) {
//            if (nums[i]!=val) {
//                i++;
//            }else if (nums[j]!=val) {
//                nums[i]=nums[j];
//                i++;
//                j--;
//            }else{
//                j--;
//            }
//        }
//        return  j+1;
//    }
//};

//@lc code=begin
class Solution {
public:
    int  removeElement (vector<int>& nums,  int val ){
        int slow =0;
        for (int fast= 0; fast < nums.size(); fast++) {
            if(nums[fast]!=val){
                nums[slow++]=nums[fast]; 
            }
        }
        return  slow;
    }    
};
//@lc code=end



int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int val;
    LeetCodeIO::scan(cin, val);

    Solution *obj = new Solution();
    auto res = obj->removeElement(nums, val);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
