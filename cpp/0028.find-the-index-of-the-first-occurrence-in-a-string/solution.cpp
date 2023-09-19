// Created by EdwardWong1994 at 2023/09/19 22:44
// leetgo: 1.3.8
// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int strStr(string haystack, string needle) {
        //查找一个字符串是否在另一个字符串中出现过
        //尝试使用朴素的模式匹配算法
        int loc=0;
        bool status = false;
        for(int i=0; i<haystack.size();){
            int  j=0;
            int  tmp=i;
            for(;j<needle.size();){
                if(haystack[i]==needle[j]){
                    i++;
                    j++;
                }else{
                    break;
                }
            }
            if(j==needle.size()) { 
                status=true;
                loc=i;
                break;
            }else{
                i=tmp+1;
            }
        } 
        return (status==true)?(loc-needle.size()):-1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string haystack;
    LeetCodeIO::scan(cin, haystack);
    string needle;
    LeetCodeIO::scan(cin, needle);

    Solution *obj = new Solution();
    auto res = obj->strStr(haystack, needle);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
