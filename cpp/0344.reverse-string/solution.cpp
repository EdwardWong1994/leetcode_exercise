// Created by EdwardWong1994 at 2023/09/17 13:20
// leetgo: 1.3.8
// https://leetcode.cn/problems/reverse-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void reverseString(vector<char>& s) {
        //因为本题要求使用`O(1)`的额外空间，所以使用双指针来操作
        int left=0;
        int right=s.size()-1;
        while(left<right){
            // char tmp = s[right];
            // s[right]=s[left];   
            // s[left]=tmp;
            s[left]^=s[right];
            s[right]^=s[left];
            s[left]^=s[right];
            left++;
            right--;
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<char> s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();
    auto res = obj->reverseString(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
