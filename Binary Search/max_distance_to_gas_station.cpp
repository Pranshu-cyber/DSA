#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int>&nums, int k, double mid){
    int n=nums.size(),cnt=0;
    for(int i=1;i<n;i++){
        int gap=nums[i]-nums[i-1];
        cnt+=ceil((double)gap/mid)-1;
    }
    return (cnt<=k);
}
double max_distance(int n, vector<int>&nums, int k){
    double st=1e-6,end=nums[n-1]-nums[0],ans=-1;
    while(end-st>1e-6){
        double mid=st+(end-st)/2;
        if(isvalid(nums, k, mid)){
            ans=mid;
            end=mid;
        }else{
            st=mid;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    cout<<max_distance(nums.size(),nums,10)<<endl;
    return 0;
}