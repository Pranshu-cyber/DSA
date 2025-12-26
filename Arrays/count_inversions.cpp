#include<bits/stdc++.h>
using namespace std;

//Brute Force
int countInversions(vector<int>&nums){
    int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[i])ans++;
        }
    }
    return ans;
}

//Optimal Approach
int merge_arr(vector<int>&nums, int low,int mid,int high);
int merge_sort(vector<int>&nums,int low,int high){
    int ans=0;
    if(low<high){
        int mid=low+(high-low)/2;
        ans+=merge_sort(nums,low,mid);
        ans+=merge_sort(nums,mid+1,high);
        ans+=merge_arr(nums,low,mid,high);
    }
    return ans;
}
int merge_arr(vector<int>&nums, int low, int mid, int high){
    vector<int>a,b;
    for(int i=low;i<=mid;i++){
        a.push_back(nums[i]);
    }
    for(int i=mid+1;i<=high;i++){
        b.push_back(nums[i]);
    }
    int i=0,j=0,n1=mid-low+1,n2=high-mid,k=low;
    int cntInv=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j])nums[k++]=a[i++];
        else{
            nums[k++]=b[j++];
            cntInv+=(n1-i);
        }
    }
    while(i<n1)nums[k++]=a[i++];
    while(j<n2)nums[k++]=b[j++];
    return cntInv;
}