#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        next=nullptr;
    }
    ListNode(int val, ListNode* ptr){
        this->val=val;
        next=ptr;
    }
};

class myqueue{
    ListNode* head,*tail;
    public:
    myqueue(){
        head=nullptr;
        tail=nullptr;
    }
    void push(int x){
        ListNode* newNode=new ListNode(x);
        tail=newNode;
        if(!head)head=newNode;
    }
    int peek(){
        return head->val;
    }
    int pop(){
        int k=head->val;
        ListNode* trk=head;
        head=head->next;
        delete trk;
        return k;
    }
    bool empty(){
        return (head==nullptr);
    }
};