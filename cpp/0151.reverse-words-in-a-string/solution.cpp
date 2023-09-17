// Created by EdwardWong1994 at 2023/09/17 18:33
// leetgo: 1.3.8
// https://leetcode.cn/problems/reverse-words-in-a-string/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
#include "algorithm"
using namespace std;

// @lc code=begin

class Solution {
public:

    void reverse(string & s,int begin, int end){
        int left=begin, right=end;
        while(left<right){
            s[left]^=s[right];
            s[right]^=s[left];
            s[left]^=s[right];
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        //删除中间的空格
        for(int i=0;i<s.size();++i){
            if(s[i]==s[i+1] && s[i]==' '){
                s.erase(s.begin()+i);
                i--;
            }
        }
        //删除前置空格
        if(s.size()>0 && s[0]==' ') s.erase(s.begin());
        //删除后置空格
        if(s.size()>0 && s[s.size()-1]==' ') s.erase(s.begin()+s.size()-1); 
        //先整体进行翻转 
        reverse(s,0,s.size()-1);
        int  tmp=0; 
        for(int i=0;i<=s.size();++i){
            if(i==s.size() || s[i]==' ' ){
                reverse(s,tmp,i-1);
                tmp=i+1;
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

    Solution *obj = new Solution();
    auto res = obj->reverseWords(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
