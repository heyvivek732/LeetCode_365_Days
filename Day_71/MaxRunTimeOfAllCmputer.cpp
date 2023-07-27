#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

bool IsPossible(vector<int>&arr,long long tm,int cmp){
    long long totalTime=0;
    for(long long it:arr){
        totalTime+=(it<tm)?it:tm;
    } 
    return (totalTime>=tm*cmp);
}
    long long maxRunTime(int n, vector<int>& arr) {
       long long ans=0;
       long long low=0;
       long long high=1e14;  // 1e9 * 1e5 = 1e14

       while(low<=high){
           long long mid=(low+high)>>1;
           if(IsPossible(arr,mid,n)){
               ans=mid;
               low=mid+1;
           }
           else{
               high=mid-1;
           }
       }
    return ans;

    }
};