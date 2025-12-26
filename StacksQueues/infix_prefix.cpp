#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter a valid infix expression:";
    cin>>s;
    reverse(s.begin(),s.end());//'(' -> ')' and vice versa
    string ans;
    stack<char>st;
    for(char c:s){
        if(isalnum(c))ans+=c;
        else if(c==')')st.push(c);
        else if(c=='('){
            while(!st.empty() && st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }else if(c=='^'){
            while(!st.empty() && st.top()==c){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }else if(c=='*' || c=='/'){
            while(!st.empty() && (st.top()=='^' || st.top()=='*' || st.top()=='/')){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }else{
            while(!st.empty() && st.top()!=')'){
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

    reverse(ans.begin(),ans.end());
    cout<<"Prefix expression:"<<ans<<endl;
    return 0;
}