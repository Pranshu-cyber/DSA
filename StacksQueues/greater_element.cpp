#include<bits/stdc++.h>
using namespace std;

vector<int>next_greater(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=-1;
            st.push(nums[i]);
        }else{
            if(st.top()>nums[i]){
                ans[i]=st.top();
                st.push(nums[i]);
            }else{
                while(!st.empty() && st.top()<=nums[i])st.pop();
                if(st.empty()){
                    ans[i]=-1;
                    st.push(nums[i]);
                }else{
                    ans[i]=st.top();
                }
            }
        }
    }
    return ans;
}

vector<int>prev_greater(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            ans[i]=-1;
            st.push(nums[i]);
        }else{
            if(st.top()>nums[i])ans[i]=st.top();
            else{
                while(!st.empty() && st.top()<=nums[i])st.pop();
                if(!st.empty())ans[i]=st.top();
                else{
                    ans[i]=-1;
                }
            }
            st.push(nums[i]);
        }
    }
    return ans;
}
int main(){
    vector<int>arr={3,4,5,1,5,8};
    vector<int>res=prev_greater(arr);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}
