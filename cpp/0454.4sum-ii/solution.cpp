// Created by EdwardWong1994 at 2023/09/09 23:20
// leetgo: 1.3.8
// https://leetcode.cn/problems/4sum-ii/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        int result=0;
        for(int i=0;i<nums1.size();++i){
            for(int j=0;j<nums2.size();++j){
                map1[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<nums3.size();++i){
            for(int j=0;j<nums4.size();++j){
                map2[nums3[i]+nums4[j]]++;
            }   
        }
        for(auto & it :map1){
            int tmp = - (it.first);
            auto it1 = map2.find(tmp);  
            if(it1!=map2.end()){   
                result+=(it.second)*(it1->second);
            }
        } 
        return result;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);
    vector<int> nums3;
    LeetCodeIO::scan(cin, nums3);
    vector<int> nums4;
    LeetCodeIO::scan(cin, nums4);

    Solution *obj = new Solution();
    auto res = obj->fourSumCount(nums1, nums2, nums3, nums4);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
