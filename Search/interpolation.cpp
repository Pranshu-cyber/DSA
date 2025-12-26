#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={1,89,264,5123652};
    int search=264;
    int st=0,end=nums.size()-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(search-nums[st])/(nums[end]-nums[st])*(end-st);
        if(nums[mid]==search){ans=mid;break;}
        else if(nums[mid]>search)end=mid-1;
        else st=mid+1;
    }
    cout<<"Element found at "<<ans<<endl;
    return 0;
}