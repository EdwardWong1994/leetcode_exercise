// Created by EdwardWong1994 at 2023/09/03 19:51
// leetgo: 1.3.7
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //这个题不需要定义dummyNode就行
        if(head==nullptr)  return head;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next=head;
        ListNode*  pointer1 = dummyNode;
        ListNode*  pointer2 = dummyNode; 
        int nums=n-1;
        while(nums--){
            pointer2=pointer2->next;
        }
        ListNode*  tmp =new ListNode(0);
        while(pointer2->next!=nullptr){
            tmp=pointer1;
            pointer1=pointer1->next;
            pointer2=pointer2->next;
        }
        //  下面要进行删除节点操作
        tmp->next=pointer1->next;
        return  dummyNode->next;
    }

};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->removeNthFromEnd(head, n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
