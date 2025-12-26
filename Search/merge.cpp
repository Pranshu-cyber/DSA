#include<bits/stdc++.h>
using namespace std;
void merge_arr(vector<int>&nums,int low, int mid, int high){
    int n1=mid-low+1,n2=high-mid;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++)a[i]=nums[low+i];
    for(int i=0;i<n2;i++)b[i]=nums[mid+i+1];
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(a[i]<=b[j])nums[k++]=a[i++];
        else nums[k++]=b[j++];
    }
    while(i<n1)nums[k++]=a[i++];
    while(j<n2)nums[k++]=b[j++];
}
void merge_sort(vector<int>&nums,int low, int high){
    if(low<high){
        int mid=low+(high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge_arr(nums,low,mid,high);
    }
}
int main(){
    vector<int>nums={6,1,874,6,2,6,52,6,52};

}