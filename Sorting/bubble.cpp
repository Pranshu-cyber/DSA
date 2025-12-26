#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={8,1,6,26,5,2,6,5,2,65,8};
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(nums[j]>nums[j+1])swap(nums[j],nums[j+1]);
        }
    }
    cout<<"Sorted:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}