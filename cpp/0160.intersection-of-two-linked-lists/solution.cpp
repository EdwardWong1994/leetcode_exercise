// Created by EdwardWong1994 at 2023/09/04 07:06
// leetgo: 1.3.7
// https://leetcode.cn/problems/intersection-of-two-linked-lists/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countLink(ListNode* head);
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr)  return nullptr;
        int countA = countLink(headA);
        int countB = countLink(headB);
        int nums = countA-countB;
        ListNode*curA = headA;
        ListNode*curB = headB;
        if(nums>0){
            while(nums--){
                curA=curA->next;
            } 
        }else{
            while((nums++)!=0){
                curB=curB->next;
            }
        }
        //然后从这开始，遍历链表A和链表B，比较节点是否一样
        ListNode * tmp=curA;
        //  while(curA!=nullptr){   //一定会同时到达最后一个节点
        //      if(curA->val==curB->val){
        //          curA=curA->next;
        //          curB=curB->next;
        //      }else{
        //          curA=curA->next;
        //          curB=curB->next;
        //          tmp=curA;
        //      }
        //      //   if(curA==curB)  return curA;  其实只要比较curA==curB就好，没必要比较curA->val==curB->val
        //      //   curA=curA->next;
        //      //   curB=curB->next;
        //  }//
        //  return tmp;
        while(curA!=nullptr){
            if(curA==curB)  return curA; // 其实只要比较curA==curB就好，没必要比较curA->val==curB->val
            curA=curA->next;
            curB=curB->next;
        }
        return nullptr;
    }
};

int Solution::countLink(ListNode* head){
    int count=0;
    ListNode* tmp = head;
    while(tmp!=nullptr){
        count++;
        tmp=tmp->next;
    }
    return count;
}

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int intersectVal;
    LeetCodeIO::scan(cin, intersectVal);
    ListNode* listA;
    LeetCodeIO::scan(cin, listA);
    ListNode* listB;
    LeetCodeIO::scan(cin, listB);
    int skipA;
    LeetCodeIO::scan(cin, skipA);
    int skipB;
    LeetCodeIO::scan(cin, skipB);

    Solution *obj = new Solution();
    auto res = obj->getIntersectionNode(intersectVal, listA, listB, skipA, skipB);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
