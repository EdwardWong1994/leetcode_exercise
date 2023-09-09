// Created by EdwardWong1994 at 2023/09/04 06:41
// leetgo: 1.3.7
// https://leetcode.cn/problems/reverse-integer/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int reverse(int x) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int x;
	LeetCodeIO::scan(cin, x);

	Solution *obj = new Solution();
	auto res = obj->reverse(x);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
