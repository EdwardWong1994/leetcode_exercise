// Created by EdwardWong1994 at 2023/09/17 14:01
// leetgo: 1.3.8
// https://leetcode.cn/problems/reverse-string-ii/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

//这种解答方式比标准答案麻烦

// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         //剩余的字符串的数量
//         int nums = s.size();
//         if(nums>=2*k){
//             for(int i=0;i<s.size();i+=2*k){
//                 swap(&(s[i]),k);
//                 nums=nums-2*k;
//                 if(nums<2*k) break;
//             } 
//         }
//         if(nums>=k && nums<2*k){
//             swap(&(s[s.size()-nums]),k);
//         }
//         if(nums>=0 && nums<k){
//             swap(&(s[s.size()-nums]),nums);
//         }
//         return s;
//     }
//
//     void swap(char *p, int num){
//         int left=0, right=num-1;
//         while(left<right){
//             // p[left]^=p[right];
//             // p[right]^=p[left];
//             // p[left]^=p[right];
//             int tmp =*(p+right);
//             *(p+right)=*(p+left);
//             *(p+left)=tmp;
//             left++;
//             right--;
//         }
//     }
//
// };

//使用

class Solution{
public:
    string  reverseStr(string s, int k){
        for(int i=0;i<s.size();i+=(2*k)){
            if(i+k<=s.size()) {
                reverse(s.begin()+i, s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};


// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->reverseStr(s, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
