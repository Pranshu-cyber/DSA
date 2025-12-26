#include<bits/stdc++.h>
using namespace std;

vector<int> sortKsorted(vector<int>&nums, int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;
    for(int i=0;i<=k;i++){
        pq.push(nums[i]);
    }
    for(int i=k+1;i<nums.size();i++){
        ans.push_back(pq.top());
        pq.pop();
        pq.push(nums[i]);
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int>nums={1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    vector<int>ans=sortKsorted(nums,2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}