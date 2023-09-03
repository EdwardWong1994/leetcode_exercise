
#include<iostream>
#include<vector>
using namespace  std;

class  ListNode{
public:
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int  x):val(x),next(nullptr){};
    ListNode(int  x, ListNode* pointer):val(x),next(pointer){};
    ListNode*  createList(ListNode* head,  vector<int> &vec);
    void ListPrint(ListNode* node);
    ListNode* swapPairs(ListNode* head);

};


ListNode* ListNode::createList(ListNode* head , vector<int> & vec){   

    ListNode* dummyNode=new ListNode(0);   //创建的是一个dummyNode；
    head=dummyNode;
    for(int nums:vec){
        ListNode* node=new ListNode(nums);
        head->next=node;
        head=head->next;
    }
    return dummyNode;           //返回的是dummyNode，因为接下来还要进行swapPairs函数的交换
}

ListNode* ListNode::swapPairs(ListNode* head) {   //传入的是dummyNode；
    if(head->next==nullptr || head->next->next==nullptr) return head;
    ListNode* cur=head;
    ListNode* nex = head->next;
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

    return head->next;
}

void ListNode::ListPrint(ListNode* head){   //这里的head是dummyNode->next
    ListNode * cur=head;
    while(cur!=nullptr){
        printf("%d\n",cur->val);
        cur=cur->next;
    }
}


int main(){
    vector<int> vec={1,2};
    ListNode* node1 = new  ListNode();
    ListNode* dummyNode=nullptr;
    ListNode* result;
    dummyNode =  node1->createList(dummyNode,vec);  //传入的是dummyNode
    result=node1->swapPairs(dummyNode);   //传入的是dummyNode,输出的是dummyNode->next
    node1->ListPrint(result);
    return 0;
}
