// Created by EdwardWong1994 at 2023/09/09 17:38
// leetgo: 1.3.8
// https://leetcode.cn/problems/valid-anagram/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isAnagram(string s, string t) {
        //定义两个数组
        int A[26] ={0};   //注意A[26】是有26个单词
        int i=0;
        int  j=0;
        while(s[i]!='\0'){
            //其实并不需要知道字符的具体ascii值，只需要知道相对值即可
            A[s[i++]-'a']+=1;
        } //先循环遍历string s，然后向数组中不断加1
        while(t[j]!='\0'){
            A[t[j++]-'a']-=1;
        }   //循环遍历string t，然后不断向数组中减1
        //循环判断数组A中是否有不为0的值，如果有的话，就说嘛不是字母异位词
        for(int i=0; i<=25; i++){
            if(A[i]!=0) return false;
        }
        return  true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);
    string t;
    LeetCodeIO::scan(cin, t);

    Solution *obj = new Solution();
    auto res = obj->isAnagram(s, t);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
