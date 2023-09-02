## 出现了死循环的问题

这是因为在写`Ele_num`函数时，忘记更新了指针，，结果导致出现死循环

```

int Nums_Ele(){
    ListNode*  cur = dummyNode;
    while(cur->next!=nullptr){
        cur=cur->next;
        count++;    //count其实记录的是元素的个数
    } 
    return count;   //这个count返回的是元素的实际个数，不包含dummyNode节点
}
```

## 很多次都不能AC，出现错误

后来找到问题在于循环边界的处理存在错误，尤其要注意在写`void  AddIndex(int  index, int val) `  函数时，需要注意可以在最后一个元素后添加元素。

```
void AddIndex(int index, int val){
    if(index<0)  index=0;
    if(index > count) return;    //就是因为这个边界条件，始终不能AC

    ListNode* cur = dummyNode;
    while(index--){
        cur=cur->next;
    }
    ListNode*  Node = new ListNode(val);
    Node->next=cur->next;
    cur->next=Node;
}

```

## 不知道为何一直AC不了，出现 `member access within null pointer of type 'ListNode'`

等待解决？？？
