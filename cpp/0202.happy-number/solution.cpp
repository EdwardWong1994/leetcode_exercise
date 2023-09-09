// Created by EdwardWong1994 at 2023/09/09 19:53
// leetgo: 1.3.8
// https://leetcode.cn/problems/happy-number/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:

    int square(int n){
        int quotient =  n;
        int remainder =0;
        int result=0;
        while(quotient!=0){
            remainder=quotient%10;
            quotient=quotient/10;
            result+=remainder*remainder;
        }
        return result;
    }

    bool isHappy(int n) {
        unordered_set<int> set1;
        int tmp =n;
        while(1){
            if(tmp==1) return true;
            unordered_set<int>::iterator it = set1.find(tmp);
            if(it==set1.end()) {
                set1.insert(tmp);
                 tmp =square(tmp);
            }else{
                return false;
            }
        }
    }

};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->isHappy(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
