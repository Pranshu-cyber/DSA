#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&nums1,vector<int>&nums2,int ele){
    int cnt=0;
    cnt+=upper_bound(nums1.begin(),nums1.end(),ele)-nums1.begin();
    cnt+=upper_bound(nums2.begin(),nums2.end(),ele)-nums2.begin();
    return cnt;
}
int kth_element(vector<int>&nums1,vector<int>&nums2,int k){
    int m=nums1.size(),n=nums2.size(),ans=-1;
    int st=min(nums1[0],nums2[0]),end=max(nums1[m-1],nums2[n-1]);
    while(st<=end){
        int mid=st+(end-st)/2;
        int trk=helper(nums1,nums2,mid);
        if(trk>=k){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums1={100, 112, 256, 349, 770},nums2={72, 86, 113, 119, 265, 445, 892};
    cout<<kth_element(nums1,nums2,7)<<endl;
    return 0;
}