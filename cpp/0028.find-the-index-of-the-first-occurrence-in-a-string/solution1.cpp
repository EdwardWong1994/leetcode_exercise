#include "iostream"
#include <string>
using namespace  std;


class Solution {
public:
    int strStr1(string haystack, string needle) {
        //查找一个字符串是否在另一个字符串中出现过
        //尝试使用朴素的模式匹配算法
        int loc=0;
        bool status = false;
        for(int i=0; i<haystack.size();){
            int  j=0;
            int tmp =i;
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

int main(){
    string  s1= "mississippi";
    string  s2="issip";
    Solution  sol;
    int n=sol.strStr1(s1,s2);
    std::cout<<n;
    return 0;

}
