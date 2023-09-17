#include "iostream"
#include "string"
using namespace  std;

class subStr{
public:
    string substitute(string s);
};

string  subStr::substitute(string  s){
    //首先判断有多少个空格
    int count=0; 
    for(int i=0;i<s.size();++i){
        if(s[i]==' ')  count++;  
    }

    int nums=count*2+s.size();
    int nums1 = s.size();
    //直接原地操作字符串,因此需要对字符串进行扩容
    s.resize(nums);
    for(int i=nums1-1,j=nums-1;i>=0;i--,j--){
        if(s[i]==' '){
            s[j]='0';
            s[j-1]='2';
            s[j-2]='%';
            j=j-2;
            // nums--;
        }else{
            s[j]=s[i];
            // nums--/* / */* ; */
        }
    }
    return s;
}


int main(){
    string s="We are happy";
    subStr str;
    string s1=str.substitute(s);
    for(int i=0; i<s1.size();++i){
        std::cout<<s1[i];
    }
    return  0;     
}
