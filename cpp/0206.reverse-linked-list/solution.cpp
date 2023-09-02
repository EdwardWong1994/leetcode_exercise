// Created by EdwardWong1994 at 2023/09/02 14:00
// leetgo: 1.3.7
// https://leetcode.cn/problems/reverse-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        //使用循环不断反转列表，在翻转链表的时候需要一个tmp节点记住位置
//        if(head ==nullptr)  return nullptr;
//        if(head->next==nullptr) return head;   //如果只有一个元素，那么直接返回head就行
//        ListNode* dummyNode = nullptr;
//        ListNode* prev =dummyNode;
//        ListNode* cur=head;
//        while(cur->next!=nullptr){
//            ListNode* tmp=cur->next;
//            cur->next=prev;
//            prev=cur;
//ListNode* prev = nullptr;
//ListNode* cur = head;
//            cur=tmp;     
//        }
//        cur->next=prev;    // 最后要记住将最后一个节点连接上
//        return cur;
//    }
//};


//从前向后递归
//
//class Solution{
//public:
//
//    ListNode*  reverse(ListNode* prev, ListNode* cur){
//        if(cur==nullptr) return prev;    //记住这个地方要返回的是prev，而不是cur
//        ListNode* tmp =cur->next;
//        cur->next=prev;
//        return reverse(cur,tmp);    //虽然这个reverse函数是有返回值的，但不是每次在调用自己时都需要给一个变量把他的值接住
//    }
//
//    ListNode* reverseList(ListNode* head){
//        //使用递归来解决问题
//        //需要递归终止条件
//        //if(head==nullptr)  return  nullptr;
//        //if(head->next==nullptr) return head;
//        return reverse(nullptr, head);
//    }
//};
//
// 从后向前翻转的递归实现
class Solution{
public:
    ListNode* reverseList(ListNode*  head){
        //递归终止条件
        if(head==nullptr)  return  head;
        if(head->next==nullptr)  return head;
        //翻转从第二个节点之后的链表
        ListNode* node = reverseList(head->next);
        //翻转第二个节点和第一个节点的指向
        head->next->next=head;
        //翻转第一个节点和第二个节点的指向
        head->next=nullptr;
        return node;
    }
};
// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    ListNode* prev =reverseList(head);
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();
    auto res = obj->reverseList(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
