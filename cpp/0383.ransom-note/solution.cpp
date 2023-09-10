// Created by EdwardWong1994 at 2023/09/10 13:52
// leetgo: 1.3.8
// https://leetcode.cn/problems/ransom-note/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         std::multiset<char> mset;
//         for(auto s:magazine){
//             mset.insert(s);     
//         }
//         for(auto t:ransomNote){
//             multiset<char>::iterator it = mset.find(t);
//             if(it!=mset.end()){
//                 mset.erase(it);
//             }else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };
//
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        //使用数组作为哈希表的容器
        //字母作为索引，字母出现的次数作为数组的值
        int A[27]={0};
        for(auto s:magazine){
            A[s-'a']++;
        }
        for(auto t: ransomNote){
            A[t-'a']--;
        }
        for(int i=0; i<=26;++i){
            if(A[i]<0) return  false;
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string ransomNote;
    LeetCodeIO::scan(cin, ransomNote);
    string magazine;
    LeetCodeIO::scan(cin, magazine);

    Solution *obj = new Solution();
    auto res = obj->canConstruct(ransomNote, magazine);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
