#include<bits/stdc++.h>
using namespace std;
// Unique Permutation
//Better Using set DS
class Solution {
public:
void solve(vector<int>&arr,set<vector<int>>&st,vector<int>&temp,int mark[]){
    if(temp.size()==arr.size()){
        st.insert(temp);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(!mark[i]){
            mark[i]=1;
            temp.push_back(arr[i]);
            solve(arr,st,temp,mark);
            mark[i]=0;
            temp.pop_back();
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>temp;
        int mark[nums.size()];
       memset(mark,0,sizeof(mark));
        solve(nums,st,temp,mark);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
// Most Optimal
class Solution {
public:
void solve(vector<int> num, int ind, int n, vector<vector<int> > &ans) {
        if (ind == n-1) {
            ans.push_back(num);
            return;
        }
        for (int i = ind; i < n; i++) {
            if (ind != i && num[ind] == num[i]) continue;
            swap(num[ind], num[i]);
            solve(num, ind+1, n, ans);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        solve(num, 0, num.size(), res);
        return res;
    }
};