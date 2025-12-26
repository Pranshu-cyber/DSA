#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={1,9,58,32581,523251};
    int search=9;
    int ans=-1;
    int st=0,end=nums.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==search){
            ans=mid;
            break;
        }
        else if(nums[mid]>search)end=mid-1;
        else{
            st=mid+1;
        }
    }
    cout<<"Element found at "<<ans<<endl;
    return 0;
}