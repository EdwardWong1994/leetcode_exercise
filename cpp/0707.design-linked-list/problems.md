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
