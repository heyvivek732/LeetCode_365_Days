#include<bits/stdc++.h>
using namespace std;
/*
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller 
*/

// Using Weighted Median TC: NLongn  SC: O(N)
long long solve(vector<int>&arr,vector<int>&cost,int x){
    long long res=0;
    for(int i=0;i<arr.size();i++){
        res+=1L*abs(arr[i]-x)*cost[i];
    }
    return res;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
      vector<pair<int,int>>p;
      long long ans=0,sum=0,med;
    for(int i=0;i<nums.size();i++){
        p.push_back({nums[i],cost[i]});
    }
    sort(p.begin(),p.end());
    for(int i=0;i<cost.size();i++){
    sum+=p[i].second;
    }

    int i=0;
    while(ans<(sum+1)>>1 && i<nums.size()){
        ans+=p[i].second;
        med=p[i].first;
        i++;
    }
        return solve(nums,cost,med);
    }
// Ternary Search O(nlong) SC:O(1)
long long solve(vector<int>&arr,vector<int>&cost,int x){
    long long res=0;
    for(int i=0;i<arr.size();i++){
        res+=1L*abs(arr[i]-x)*cost[i];
    }
    return res;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
      long long low=1,high=1e6,res=solve(nums,cost,1),x;

      while(low<high){
          x=(low+high)>>1;
          long long y1=solve(nums,cost,x),y2=solve(nums,cost,x+1);
          res=min(y1,y2);
          if(y1<y2){
              high=x;
          }else{
              low=x+1;
          }
      }
      return res;
    }
};


