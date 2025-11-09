#include<iostream>
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

class mystack{
    ListNode* head;
    public:
    mystack(){
        head=nullptr;
    }
    void push(int x){
        ListNode* newNode=new ListNode(x, head);
        head=newNode;
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
    int top(){
        return head->val;
    }
};