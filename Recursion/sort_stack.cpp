#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&s,int x){
    if(s.empty() || s.top()<=x){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,x);
    s.push(temp);
}
void sortstack(stack<int>&s){
    if(s.empty())return;
    int x=s.top();
    s.pop();
    sortstack(s);
    insert(s,x);
}