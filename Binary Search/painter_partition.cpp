#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int>&nums, int a, int mid){
    int n=nums.size();
    int cnt=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>mid){
            sum=nums[i];
            cnt++;
        }else{
            sum+=nums[i];
        }
    }
    return (cnt<=a);
}
int painter_partition(int a,int b, vector<int>&nums){
    int n=nums.size(),mod=10000003,ans=0;
    int st=*max_element(nums.begin(),nums.end()),end=accumulate(nums.begin(),nums.end(),0);
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(nums,a,mid)){
            ans=int((long long)(mid*b)%mod);
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={1,8,11,3};
    cout<<painter_partition(10,1,nums)<<endl;
    return 0;
}