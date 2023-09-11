#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
           if(mp.find(arr[i])!=mp.end()){
               mp[arr[i]].push_back(i);
           }else{
               mp[arr[i]]=vector<int>{i};
           }
           if(mp[arr[i]].size()==arr[i]){
               ans.push_back(mp[arr[i]]);
               mp.erase(arr[i]);
           }
        }
        return ans;
    }
};