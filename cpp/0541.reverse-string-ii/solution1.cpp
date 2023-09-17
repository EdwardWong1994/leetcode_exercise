#include "iostream"
#include "string"
using namespace  std;


class Str{
public:
    string strReverse(string s, int k);
    void swap(char* p, int num);
}; 

void  Str::swap(char *p, int num){
    int left=0, right=num-1;
    while(left<right){
        // p[left]^=p[right];
        // p[right]^=p[left];
        // p[left]^=p[right];
        int tmp =*(p+right);
        *(p+right)=*(p+left);
        *(p+left)=tmp;
        left++;
        right--;
    }
}

string  Str::strReverse(string s, int k){
    int nums = s.size();
    if(nums>=2*k){
        for(int i=0;i<s.size();i+=2*k){
            swap(&(s[i]),k);
            nums=nums-2*k;
            if(nums<2*k) break;
        } 
    }
    if(nums>=k && nums<2*k){
        swap(&(s[s.size()-nums]),k);
    }
    if(nums>=0 && nums<k){
        swap(&(s[s.size()-nums]),nums);
    }
    return s;
}

int main(){
    Str str;
    string string1="abcdefg";
    int k=3;
    string1 = str.strReverse(string1,k);
    for(int i=0; i<string1.size();++i){
        std::cout<<string1[i]<<std::endl;
    }
}
