// Created by EdwardWong1994 at 2023/09/02 20:48
// leetgo: 1.3.7
// https://leetcode.cn/problems/swap-nodes-in-pairs/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin
class Solution{
public:
    ListNode*  swapPairs(ListNode* head) {  
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next=head;
        ListNode* cur=dummyNode;
        ListNode* nex = cur->next;
        ListNode* tmp=nex->next;

        while(cur->next!=nullptr &&  cur->next->next!=nullptr  &&  cur->next->next->next!=nullptr) {
            ListNode*  node1=tmp->next;
            tmp->next=nex;    //步骤一
           cur->next=tmp;    //步骤二
            nex->next=node1;  //步骤三
            cur=nex;
            //   if(){
            //   }
            nex=node1;
            tmp=node1->next;
        }
        if (cur->next->next!=nullptr) {
            cur->next=tmp;
            tmp->next=nex;
            nex->next=nullptr;    //一定要指明nex->next=nullptr,要不然在print的时候会死循环
        }

        return dummyNode->next;
    }
};
//class  Solution{
//public:
//    ListNode* swapPairs(ListNode* head){
//        ListNode*  dummyNode = new ListNode(0);
//        dummyNode->next=head;
//        ListNode* cur=dummyNode;    
//        while(cur->next!=nullptr && cur->next->next!=nullptr){
//            ListNode* tmp =  cur->next;
//            ListNode* tmp1 = cur->next->next->next; 
//            cur->next=cur->next->next;
//            cur->next->next=tmp;
//            cur->next->next->next=tmp1;
//            cur=cur->next->next;
//        }
//        return dummyNode->next;
//    }
//};


// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();
    auto res = obj->swapPairs(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
