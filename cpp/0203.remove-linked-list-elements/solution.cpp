// Created by EdwardWong1994 at 2023/08/31 10:39
// leetgo: 1.3.7
// https://leetcode.cn/problems/remove-linked-list-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

//一定要自己会写链表
//
//struct ListNode {
//    int      val;
//    ListNode*  next;    
//    ListNode():x(0),next{nullptr}{};
//    ListNode(int x):node(x),next{nullptr}{};
//    ListNode(int x,ListNode*  next):node(x),next(next){};
//};



// @lc code=begin
// 这段代码中记录了之前node位置和现在node的位置，这样在使用while(cur->next!=nullptr)进行判断时会忽略最后一个元素。需要在最后额外判断
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        //需要增加对传入的链表是否是空进行判断
//        if(head==nullptr) return head;
//        ListNode*  dummyNode=new ListNode(0);
//        dummyNode->next=head;
//        //在删除的过程首先需要做的是从头遍历整个链表
//        ListNode* prev;    //用于记录等于val值之前的那个链表节点
//        prev = dummyNode;
//        ListNode* cur=dummyNode->next;   //用于记录当前节点
//        while(cur->next!=NULL){    //这样写的话会对最后一个元素判断不了
//            if (cur->val==val) {
//                //考虑移除元素,移除元素只需要进行指针的调整即可，但是需要记录prev链表节点
//                ListNode*  tmp= cur;    //专门用来删除节点的
//                prev->next=cur->next;  //当前节点的值等于val，将prev的节点指向当前节点的下一个节点 
//                cur = cur->next;       //将当前节点移动到下一个节点上
//                delete tmp;
//            }else{
//                prev = cur;
//                cur=cur->next;
//            }   
//        }
//        //在这个地方需要增加对最后一个元素的判断，判断是否等于val
//        if (cur->val==val) {
//            prev->next =nullptr;
//        }
//        return dummyNode->next;  //返回的也是虚拟头节点
//    }
//};


//代码随想录提供的版本是记录当前和下一个node的位置，下面提供代码的写法
//代码随想录的答案提示我们，只需要操作两个节点即可，没必要操作三个节点
class  Solution{
public:
    ListNode*  removeElements(ListNode* head, int val){
        //定义一个dummyNode
        ListNode*  dummyNode=new  ListNode(0);
        dummyNode->next = head;

        ListNode* cur =dummyNode;  //代表当前节点
        ListNode* nex = cur->next;      //代表下一个节点

        while(nex != nullptr){
            if(nex->val==val){
                ListNode* tmp = nex;
                cur->next=nex->next;  
                nex=nex->next;
            }else{
                cur=nex;
                nex=nex->next;
            }

        }
        return dummyNode->next;
    } 

};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);
    int val;
    LeetCodeIO::scan(cin, val);

    Solution *obj = new Solution();
    auto res = obj->removeElements(head, val);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
