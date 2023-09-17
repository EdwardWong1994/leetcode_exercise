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
    string reverseWords(string& s) {
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
        reverse(s,0,s.size()-1);
        return s;
    }
};


int main(){
    Solution solution;
    string str="  the  blue sky  ";
    string str1=solution.reverseWords(str);
    for(int i=0;i<str1.size();++i){
        cout<<str1[i];
    }
    return  0;
}
