#include<bits/stdc++.h>
using namespace std;

int fruitsBaskets(vector<int>&nums){
    int n=nums.size();
    int l=0;
    int ans=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
        while(l<n && mp.size()>2){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)mp.erase(nums[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    return ans;
}

int main(){
    vector<int>nums={1,2,3,2,2};
    cout<<fruitsBaskets(nums)<<endl;
    return 0;
}