#include<bits/stdc++.h>
using namespace std;

vector<bool>seive(int n){
    vector<bool>ans(n+1,1);
    ans[0]=0;ans[1]=0;
    for(int i=2;i*i<=n;i++){
        if(ans[i]){
            for(int j=i*i;j<=n;j+=i){
                ans[j]=0;
            }
        }
    }
    return ans;
}

vector<vector<int>> prime_factors(vector<int>nums){
    int n=nums.size();
    vector<bool>check=seive(*max_element(nums.begin(),nums.end()));
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        vector<int>res;
        if(check[nums[i]])res.push_back(nums[i]);
        else{
            int k=nums[i];
            for(int j=2;j<=k;j++){
                while(k%j==0 && check[j]){
                    res.push_back(j);
                    k/=j;
                }
            }
        }
        ans.push_back(res);
    }
    return ans;
}

int main(){
    vector<int>nums={9456,780,5,96};
    vector<vector<int>>ans=prime_factors(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}