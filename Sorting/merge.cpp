#include<bits/stdc++.h>
using namespace std;

void merge_arr(vector<int>&nums, int low,int mid, int high);
void merge_sort(vector<int>&nums, int low, int high){
    if(low<high){
        int mid=low+(high-low)/2;
        merge_sort(nums, low, mid);
        merge_sort(nums,mid+1,high);
        merge_arr(nums, low, mid, high);
    }
}
void merge_arr(vector<int>&nums, int low, int mid, int high){
    vector<int>a,b;
    for(int i=low;i<=mid;i++){
        a.push_back(nums[i]);
    }
    for(int i=mid+1;i<=high;i++)b.push_back(nums[i]);
    int i=0,j=0,k=low;
    int m=a.size(),n=b.size();
    while(i<m && j<n){
        if(a[i]<=b[j])nums[k++]=a[i++];
        else nums[k++]=b[j++];
    }
    while(i<m)nums[k++]=a[i++];
    while(j<n)nums[k++]=b[j++];
}