##  Time limited exceed
```
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
```

在这段代码中必须要在while循环中判断`if(cur->next->next!=nullptr)`
 
