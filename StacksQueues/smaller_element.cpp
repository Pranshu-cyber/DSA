#include<bits/stdc++.h>
using namespace std;

vector<int>next_smaller(vector<int>& nums){
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=-1;
            st.push(nums[i]);
        }else{
            if(st.top()<nums[i])ans[i]=st.top();
            else{
                while(!st.empty() && st.top()>=nums[i])st.pop();
                if(!st.empty())ans[i]=st.top();
                else ans[i]=-1;
            }
            st.push(nums[i]);
        }
    }
    return ans;
}

vector<int>prev_smaller(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            ans[i]=-1;
        }else{
            if(st.top()<nums[i]){
                ans[i]=st.top();
            }else{
                while(!st.empty() && st.top()>=nums[i])st.pop();
                if(!st.empty())ans[i]=st.top();
                else ans[i]=-1;
            }
        }
        st.push(nums[i]);
    }
    return ans;
}