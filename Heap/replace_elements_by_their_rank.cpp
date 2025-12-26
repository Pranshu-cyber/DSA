#include<bits/stdc++.h>
using namespace std;

vector<int> replace(vector<int>&nums){
    vector<int>hlp=nums;
    unordered_map<int,int>mp;
    sort(hlp.begin(),hlp.end());
    int cnt=1,n=nums.size();
    for(int i=0;i<n;i++){
        if(mp.find(hlp[i])==mp.end())mp[hlp[i]]=cnt++;
    }
    for(int i=0;i<n;i++)hlp[i]=mp[nums[i]];
    return hlp;
}

int main(){
    vector<int>nums={1, 5, 8, 15, 8, 25, 9};
    vector<int>ans=replace(nums);
    int n=nums.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}