#include<bits/stdc++.h>
using namespace std;

long long avgWaitingTime(vector<int>&nums){
    int n=nums.size();
    long long sum=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        sum+=(n-1-i)*nums[i];
    }
    return (long long)sum/nums.size();
}

int main(){
    vector<int>nums={4, 1, 3, 7, 2};
    cout<<avgWaitingTime(nums)<<endl;
    return 0;
}