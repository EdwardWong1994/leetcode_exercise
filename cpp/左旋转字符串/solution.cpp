#include "iostream"
#include "string"
using namespace  std;


class Str{
public:
    void  reverse(string &s, int  begin, int end);
    void  LeftRotate(string& s, int n);
};

void Str::reverse(string& s, int  begin, int end){
    int left=begin, right =end;
    while(left<right){
        s[left]^=s[right];
        s[right]^=s[left];
        s[left]^=s[right];
        left++;
        right--;
    }
}

void Str::LeftRotate(string&s,int n){
    reverse(s,0,s.size()-1);
    reverse(s,0,s.size()-n-1);
    reverse(s,s.size()-n,s.size()-1);    //reverse函数书写的是前闭后闭，所以这个地方的值需要取到
}

int main(){
    string  s ="lrloseumgh";
    int n = 6;
    Str s1;
    s1.LeftRotate(s,n);
    for(auto & ch:s){
        std::cout<< ch;
    }
    return  0;
}
