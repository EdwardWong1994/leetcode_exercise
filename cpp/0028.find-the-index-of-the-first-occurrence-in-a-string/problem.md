## 在使用朴素字符串匹配算法时，有一个case始终过不了

```
input:
"mississippi"
"issip"
output:
4
```


解决办法：


使用临时变量记录`i`的位置，这样不至于跳过结果。

```
int strStr(string haystack, string needle) {
//查找一个字符串是否在另一个字符串中出现过
//尝试使用朴素的模式匹配算法
int loc=0;
bool status = false;
for(int i=0; i<haystack.size();){
int  j=0;
int  tmp=i;
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
```


###  在使用`gcc`编译的时候出现`fatal error: ../bits/stdc++.h:no such file or directory`该怎么解决
