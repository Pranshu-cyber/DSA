#include<bits/stdc++.h>
using namespace std;

int prec(char k){
    if(k=='^')return 3;
    else if(k=='*' || k=='/')return 2;
    else return 1;
}
int main(){
    string s;
    cout<<"Enter a valid infix statement:";
    cin>>s;
    stack<char>st;
    string ans;
    for(char c:s){
        if(isalnum(c))ans+=c;
        else if(c=='(')st.push(c);
        else if(c==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }else{
            while(!st.empty() && (prec(st.top())>=prec(c))){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<"Postfix:"<<ans<<endl;
    return 0;
}