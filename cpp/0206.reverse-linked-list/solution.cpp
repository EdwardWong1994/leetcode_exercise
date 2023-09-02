// Created by EdwardWong1994 at 2023/09/02 14:00
// leetgo: 1.3.7
// https://leetcode.cn/problems/reverse-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //使用循环不断反转列表，在翻转链表的时候需要一个tmp节点记住位置
        if(head ==nullptr)  return nullptr;
        if(head->next==nullptr) return head;   //如果只有一个元素，那么直接返回head就行
        ListNode* dummyNode = nullptr;
        ListNode* prev =dummyNode;
        ListNode* cur=head;
        while(cur->next!=nullptr){
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;     
        }
        cur->next=prev;    // 最后要记住将最后一个节点连接上
        return cur;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();
    auto res = obj->reverseList(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
