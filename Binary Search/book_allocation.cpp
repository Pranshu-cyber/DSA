#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int>&nums, int m, int mid){
    int n=nums.size(),cnt=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>mid){
            cnt++;
            sum=nums[i];
        }else{
            sum+=nums[i];
        }
    }
    return (cnt<=m);
}
int book_allocation(vector<int>&nums, int m){
    int n=nums.size(),ans=-1;
    int st=*max_element(nums.begin(),nums.end()),end=accumulate(nums.begin(),nums.end(),0);
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(nums, m, mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={25,46,28,49,24};
    cout<<book_allocation(nums,4)<<endl;
    return 0;
}