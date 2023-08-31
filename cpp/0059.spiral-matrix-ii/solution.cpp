// Created by EdwardWong1994 at 2023/08/30 23:41
// leetgo: 1.3.7
// https://leetcode.cn/problems/spiral-matrix-ii/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin
//这道题关键的是要始终遵循左闭右闭或者左闭右开
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>  matrix(n, vector<int>(n,0));  
        int top = 0;
        int bottom=n-1;
        int left=0;
        int right =n-1;
        int  count=1;
        int  loc_x=0;   //x的坐标
        int  loc_y=0;   //y的坐标
        while(left<=right){
            if(loc_y<right && loc_x==top){
                for (loc_y = left; loc_y < right; loc_y++) { //这里按照左闭右开的写法
                    matrix[loc_x][loc_y]=count;
                    count++;
                }
                //                loc_x++;
            }
            if(loc_y==right && loc_x<bottom){
                for (loc_x = top; loc_x < bottom; loc_x++) {
                    matrix[loc_x][loc_y]=count;
                    count++;
                }
                //                loc_y--;
            }
            if (loc_x==bottom && loc_y>left) {
                for (loc_y = right; loc_y > left; loc_y--) {
                    matrix[loc_x][loc_y]=count;
                    count++;
                }
                //                loc_x--;
            }

            if (loc_y==left && loc_x>top) {
                for (loc_x = bottom; loc_x >top; loc_x--) {
                    matrix[loc_x][loc_y]=count;
                    count++;
                }
                //                loc_y++;
            }
            if (loc_x==loc_y  && loc_x==right) {   //在写代码时容易遗漏这部分，也就是当n为奇数的时候，中间一个矩阵的元素将不会被填充
                matrix[loc_x][loc_y]=n*n;
            }
            top++;
            bottom--; 
            left++;
            right--;
            loc_x++;
            loc_y++;
        }
        return matrix;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->generateMatrix(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
