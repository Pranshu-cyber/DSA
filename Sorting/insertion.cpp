#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={98,2,64,2,6,2,3,5};
    int n=nums.size();
    for(int i=0;i<n;i++){
        int key=nums[i];
        int j=i-1;
        while(j>=0 && key<nums[j]){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
    cout<<"Sorted:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}