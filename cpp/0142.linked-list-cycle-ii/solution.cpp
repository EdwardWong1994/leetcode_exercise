// Created by EdwardWong1994 at 2023/09/09 15:05
// leetgo: 1.3.8
// https://leetcode.cn/problems/linked-list-cycle-ii/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 本题通过双指针来解题，快指针一次走两步，慢指针一次走一步，如果两个指针相遇，说明存在环。  
        //如果相遇了，让两个指针一个重新开始，然后一个指针从相遇节点同时出发，相遇的那个节点一定是环的入口
        if(head==nullptr)  return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;   
            //有可能出现fast指针已经到达nullptr了，需要判断，此时返回-1
            //如果相遇说明有环，如果没相遇说明没有环
            if(slow==fast){
                ListNode* index1  =head;   //找到相遇的节点后重置slow到开始的位置
                ListNode* index2 = fast;  //相遇后，fast指针一次移动一个节点
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);
    int pos;
    LeetCodeIO::scan(cin, pos);

    Solution *obj = new Solution();
    auto res = obj->detectCycle(head, pos);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
