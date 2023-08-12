#include<bits/stdc++.h>
using namespace std;
// Brute Force : TwoPointer Approach
//  The tle could be happen here Bacause every i we iterate whole array 
// So(n*n) TC:)(N2);
class Solution {
public:
     int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
       for(int i=0;i<n;i++){
           int j=i;
           int left=0,right=0;
           while(j>=0){
               left=max(left,height[j--]);
           }
            j=i;
           while(j<n){
               right=max(right,height[j++]);
           }
           ans+=min(left,right)-height[i];
       }
        return ans;
     }
};
// Prefix Sum Approach TC:O(N)+O(N)+O(N) = O(N) SC: O(2N) :- Two array
class Solution {
public:
    int trap(vector<int>& arr) {
       int ans=0;
       int n=arr.size();
        vector<int>pref(n,0);
        vector<int>suff(n,0);
        pref[0]=arr[0];
        suff[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],arr[i]);
        }
      for(int i=0;i<n;i++){
          ans+=min(pref[i],suff[i])-arr[i];
      }
return ans;
    }
};

// Optimal Approach : TwoPointer Approach
// TC: O(N) SC: O(1)
class Solution {
public:
     int trap(vector<int>& arr) {
       int low=0,high=arr.size()-1;
       int left_max=0,right_max=0;
       int ans=0;
       while(low<=high){
           if(arr[low]<=arr[high]){
               if(arr[low]>=left_max)left_max=arr[low];
               else ans+=left_max-arr[low];
               low++;
           }
           else {
               if(arr[high]>=right_max)right_max=arr[high];
               else ans+=right_max-arr[high];
               high--;
           }
       }
       return ans;
     }
};