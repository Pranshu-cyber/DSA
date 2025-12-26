#include<bits/stdc++.h>
using namespace std;

int minNumber(vector<int>&arrival,vector<int>&departure){
    vector<pair<int,char>>helper;
    for(int i:arrival)helper.push_back({i,'A'});
    for(int i:departure)helper.push_back({i,'D'});
    sort(helper.begin(),helper.end());
    int ans=0;
    int cnt=0;
    for(auto & p:helper){
        if(p.second=='A')cnt++;
        else cnt--;
        ans=max(ans,cnt);
    }
    return ans;
}

int main(){
    vector<int>arrival={900, 1100, 1235};
    vector<int>departure={1000, 1200, 1240};
    cout<<minNumber(arrival,departure)<<endl;
    return 0;
}