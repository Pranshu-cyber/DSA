#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int>&nums, int k, int mid){
    int n=nums.size();
    int cnt=1;
    int l=0;
    for(int i=1;i<n;i++){
        if(nums[i]-nums[l]>=mid){
            l=i;
            cnt++;
        }
    }
    return (cnt>=k);
}
int aggressive_cows(vector<int>&nums, int n, int k){
    sort(nums.begin(),nums.end());
    int st=1,end=nums.back()-nums[0],ans=0;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(nums, k, mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={4,2,1,3,6};
    cout<<aggressive_cows(nums,nums.size(),2)<<endl;
    return 0;
}