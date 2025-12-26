#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>mat,int num){
    int ans=0;
    for(int i=0;i<mat.size();i++){
        ans+=upper_bound(mat[i].begin(),mat[i].end(),num)-mat[i].begin();
    }
    return ans;
}
int kthelement(vector<vector<int>>mat,int k){
    int m=mat.size(),n=mat[0].size();
    int ans=-1;
    int st=mat[0][0],end=mat[0][n-1];
    for(int i=1;i<m;i++){
        if(mat[i][0]<st)st=mat[i][0];
        if(mat[i][n-1]>end)end=mat[i][n-1];
    }
    while(st<=end){
        int mid=st+(end-st)/2;
        int idx=helper(mat,mid);
        if(idx>=k){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int matrix_median(vector<vector<int>>mat){
    int m=mat.size(),n=mat[0].size();
    int size=m*n;
    if(size%2!=0)return kthelement(mat,(size+1)/2);
    else return (kthelement(mat,size/2)+kthelement(mat,size/2 -1))/2;
}

int main(){
    vector<vector<int>>mat1={{1,4,9},{2,5,6},{3,7,8}};
    vector<vector<int>>mat2={{1,3,8},{2,3,4},{1,2,5}};
    cout<<matrix_median(mat1)<<endl;
    cout<<matrix_median(mat2)<<endl;
    return 0;
}