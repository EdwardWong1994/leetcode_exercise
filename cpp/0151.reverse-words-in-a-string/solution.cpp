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


    //这段代码使用了erase()函数来解决问题，时间复杂度为O（n），由于外层又有一层循环，因此时间复杂度为O(n^2)
    // void remove(string &  s){
    //     //删除中间的空格
    //     for(int i=0;i<s.size();++i){
    //         if(s[i]==s[i+1] && s[i]==' '){
    //             s.erase(s.begin()+i);
    //             i--;
    //         }
    //     }
    //     //删除前置空格
    //     while(s.size()>0 && s[0]==' ') s.erase(s.begin());
    //     //删除后置空格
    //     while(s.size()>0 && s[s.size()-1]==' ') s.erase(s.begin()+s.size()-1); 
    // }
    //
    // 下面使用双指针的思路来解决问题
    void remove(string& s){
        int left=0,right =0;
        //移除前置空格
        while(right<s.size()){
            if(right==0 && s[right]==' '){
                while(right<s.size() && s[right]==' '){ //去除前面的空格
                    right++;
                }
            }else if(right<s.size() && s[right]==' ' &&s[right+1]==' '){    //后面去除空格的逻辑
                right++;
            }else{
                if(right==s.size()-1  &&  s[right]==' ')  break;
                s[left++]=s[right++];
            }
        }
        s.resize(left);     //对string s进行重新resize
    }

    //
    string reverseWords(string s) {
        //去除空格
        remove(s);
        //先整体进行翻转 
        reverse(s,0,s.size()-1);
        int  tmp=0; 
        for(int i=0;i<=s.size();++i){ //在对单词进行翻转
            if(i==s.size() || s[i]==' ' ){   //当遇到空格，说明一个单词已经解释；  //或者当到达了string s的最大长度
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
