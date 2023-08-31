#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
public:
    //初始化链表
    ListNode():val(0),next(nullptr){};
    ListNode(int x, ListNode* next):val(x),next(next){};
    ListNode(int x):val(x){};
    //创建链表
    ListNode* CreateLink(vector<int> nums);
    ListNode* removeElements(ListNode* head,int val);
    void printNode(ListNode* head);
};

ListNode*  ListNode::CreateLink(vector<int> nums){
    //创建链表的函数
    ListNode* head = nullptr, *tail = nullptr;
    for(int num:nums){
        if(head==nullptr){
            head=new ListNode(num);
            tail=head;
        }else{
            tail->next=new ListNode(num);
            tail=tail->next;
        }
    }
    //创建一个dummyNode方便以后操作：
    ListNode*  dummyNode=nullptr;
    dummyNode->next=head;
    return dummyNode;   //返回的是虚拟头节点
}

ListNode* ListNode::removeElements(ListNode* dummyNode, int val) {
    //在删除的过程首先需要做的是从头遍历整个链表
    ListNode* cur;    //用于记录等于val值之前的那个链表节点
    cur = dummyNode;   
    ListNode* nex=cur->next;   //用于记录当前节点
    while(nex!=NULL){
        if (nex->val==val) {
            //考虑移除元素,移除元素只需要进行指针的调整即可，但是需要记录prev链表节点
            ListNode*  tmp= nex;    //专门用来删除节点的
            cur->next=nex->next;  //当前节点的值等于val，将prev的节点指向当前节点的下一个节点 
            nex = nex->next;       //将当前节点移动到下一个节点上
            delete tmp;
        }else{
            cur = nex;
            nex=nex->next;
        }   
    }
    return dummyNode;  //返回的也是虚拟头节点
}

void ListNode::printNode(ListNode* dummyNode){
    ListNode* cur = dummyNode;
    if(cur->next==nullptr)  printf("No content");
    while(cur->next!=nullptr){
        printf("%d\n",cur->next->val);
        cur=cur->next;
    }
}

int main(){
    vector<int> nums={ 1,2,6,3,4,5,6 };
    int  val=6;
    ListNode* dummyNode  = new ListNode(0);
    dummyNode=dummyNode->CreateLink(nums);
    dummyNode=dummyNode->removeElements(dummyNode,val);
    dummyNode->printNode(dummyNode);
}
