#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={5,1,94,3,5,545,6,1,5,8914,63};
    int search=63;
    bool found=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==search)found=1;
    }
    if(found){
        cout<<"Element found"<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}