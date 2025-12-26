#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node* sort012(Node* head) {
    if (!head || !head->next) return head;

    Node *zeroD = new Node(-1), *oneD = new Node(-1), *twoD = new Node(-1);
    Node *zero = zeroD, *one = oneD, *two = twoD;

    Node* curr = head;
    while (curr) {
        if (curr->val == 0) {
            zero->next = curr;
            zero = zero->next;
        } 
        else if (curr->val == 1) {
            one->next = curr;
            one = one->next;
        } 
        else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // connect lists
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}
