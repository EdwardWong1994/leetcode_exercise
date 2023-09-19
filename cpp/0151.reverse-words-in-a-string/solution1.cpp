#include "iostream"
using namespace std;
#include "string"
#include "algorithm"


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


int main(){
    Solution solution;
    string str="    hello  world  ";
    string str1=solution.reverseWords(str);
    for(int i=0;i<str1.size();++i){
        cout<<str1[i];
    }
    return  0;
}
