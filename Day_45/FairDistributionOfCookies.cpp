#include<bits/stdc++.h>
using namespace std;

/*
Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
*/
class Solution {
public:
int ans=INT_MAX;
void solve(int ind,vector<int>&cookies,vector<int>&temp,int k){
    if(ind==cookies.size()){
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            maxi=max(maxi,temp[i]);
        }
        ans=min(ans,maxi);
        return;
    }
    for(int i=0;i<k;i++){
        temp[i]+=cookies[ind];
        solve(ind+1,cookies,temp,k);
        temp[i]-=cookies[ind];
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
      vector<int>temp(k,0);
      solve(0,cookies,temp,k);
      return ans;
    }
};