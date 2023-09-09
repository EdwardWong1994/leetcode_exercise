// Created by EdwardWong1994 at 2023/09/09 18:28
// leetgo: 1.3.8
// https://leetcode.cn/problems/intersection-of-two-arrays/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //本题尝试使用unordered_set来解决问题，其实只要这个容器的内容不重复就可以
        std::unordered_set<int> set1;
        vector<int> result;
        //遍历nums1，将所有的元素插入set1
        for(int i=0; i<nums1.size();++i){
            set1.insert(nums1[i]);
        }   
        for(int i=0;i<nums2.size();++i){
            unordered_set<int>::iterator it= set1.find(nums2[i]);
            if(it!=set1.end()){
                vector<int>::iterator it1 = std::find(result.begin(),result.end(),nums2[i]);
                if(it1==result.end())  result.push_back(nums2[i]);
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

    Solution *obj = new Solution();
    auto res = obj->intersection(nums1, nums2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
