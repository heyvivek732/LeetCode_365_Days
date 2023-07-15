#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
*/
class Solution {
public:
    int findMin(vector<int>& arr) {
      int ans=0;
      int n=arr.size();
      int low=0;
      int high=n-1;
      while(low<high){
        int mid=(high+low)>>1;
        if(arr[mid]>arr[high])low=mid+1;
        else{
            if(arr[mid]<arr[high])high=mid;
            else high--;
        }
      }
      return arr[high];
    }
};