#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={5,2,8,466,2,6,5,23};
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        int minidx=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[minidx])minidx=j;
        }
        swap(nums[i],nums[minidx]);
    }
    cout<<"Sorted:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}