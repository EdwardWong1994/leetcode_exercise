// Created by EdwardWong1994 at 2023/09/01 18:28
// leetgo: 1.3.7
// https://leetcode.cn/problems/design-linked-list/

#include "../bits/stdc++.h"
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class MyLinkedList {
private:
    ListNode* dummyNode = new ListNode(0);
    int count=0;
public:
    MyLinkedList() {
        //初始化链表
        //定义一个dummyNode节点
        dummyNode->next=new ListNode(0);
        // dummyNode->next =nullptr; // 对于最后一个节点指向nullptr不需要填写
    }

    //   int Nums_Ele(){
    //       ListNode*  cur = dummyNode;
    //       while(cur->next!=nullptr){
    //           cur=cur->next;
    //           count++;    //count其实记录的是元素的个数
    //       } 
    //       return count;   //这个count返回的是元素的实际个数，不包含dummyNode节点
    //   }

    int get(int index) {
        //  count=Nums_Ele();
        if (index<0 || index>(count-1)) return -1;
        //因为有dummyNode，，所以在使用index的时候要小心
        //    ListNode* cur = dummyNode;
        ListNode* nex = dummyNode->next;
        while((index--)){
            //      cur=nex;
            nex=nex->next;
        } 
        return nex->val;
    }


    void addAtHead(int val) {
        //在链表头部添加节点
        ListNode* Node = new  ListNode(val);
        //     ListNode* tmp = dummyNode->next;
        Node->next=dummyNode->next;
        dummyNode->next=Node;
        count++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyNode;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        count++;
    }


    //    void addAtTail(int val) {
    //        //在链表尾部添加节点
    //        ListNode* cur = dummyNode;
    //        ListNode* nex = dummyNode->next; 
    //        while(nex->next  != nullptr){
    //            cur=nex;
    //            nex=nex->next;
    //        }
    //        ListNode* Node = new  ListNode(val);
    //        nex->next = Node;
    //        count++;
    //    }
    //
    //
    //

    void addAtIndex(int index, int val) {

        if(index > count-1) return;
        if(index < 0) index = 0;        
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyNode;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        count++;
    }

    //    void addAtIndex(int index, int val) {
    //        //在index处前添加一个节点，考察指针的移动操作
    //        //因为dummyNode被我算作了一个节点，
    //        //   count = Nums_Ele();
    //        if(index>count-1)  return;//  完全可以在最后一个的后面添加元素
    //        if(index<0) index=0;
    //        ListNode* cur = dummyNode;
    //        ListNode* nex = dummyNode->next;
    //        while(index--){
    //            cur= nex;
    //            nex=nex->next;
    //        }
    //        ListNode* Node = new ListNode(val);
    //        cur->next=Node;
    //        Node->next=nex;
    //        count++;
    //    }
    //
    //   void deleteAtIndex(int index) {
    //       //删除在index处的节点
    //       if(index<0 || index>count-1) return;
    //       //     count = Nums_Ele();
    //       ListNode* cur =dummyNode;
    //       ListNode* nex =dummyNode->next;
    //       while(index--){
    //           cur->next=nex;
    //           nex=nex->next;
    //       }
    //       //不要忘记删除节点
    //       ListNode* tmp=nex;
    //       cur->next=nex->next;
    //       delete nex;
    //       count--;
    //   }
    void deleteAtIndex(int index) {
        if (index >= count-1 || index < 0) {
            return;
        }
        ListNode* cur = dummyNode;
        while(index--) {
            cur = cur ->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp=nullptr;
        count--;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    MyLinkedList *obj;
    const unordered_map<string, function<void()>> methods = {
        { "MyLinkedList", [&]() {
            cin.ignore();
            obj = new MyLinkedList();
            out_stream << "null,";
        } },
        { "get", [&]() {
            int index; LeetCodeIO::scan(cin, index); cin.ignore();
            LeetCodeIO::print(out_stream, obj->get(index)); out_stream << ',';
        } },
        { "addAtHead", [&]() {
            int val; LeetCodeIO::scan(cin, val); cin.ignore();
            obj->addAtHead(val);
            out_stream << "null,";
        } },
        { "addAtTail", [&]() {
            int val; LeetCodeIO::scan(cin, val); cin.ignore();
            obj->addAtTail(val);
            out_stream << "null,";
        } },
        { "addAtIndex", [&]() {
            int index; LeetCodeIO::scan(cin, index); cin.ignore();
            int val; LeetCodeIO::scan(cin, val); cin.ignore();
            obj->addAtIndex(index, val);
            out_stream << "null,";
        } },
        { "deleteAtIndex", [&]() {
            int index; LeetCodeIO::scan(cin, index); cin.ignore();
            obj->deleteAtIndex(index);
            out_stream << "null,";
        } },
    };
    cin >> ws;
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end); out_stream << ']';
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
