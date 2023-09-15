#include<bits/stdc++.h>
using namespace std;
/*
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
*/
class Solution {
public:
    int candy(vector<int>& arr) {
       int ans=0;
       int n=arr.size();
       vector<int>vec(n,1); // At Least One Candy Have
        for(int i=0;i<n;i++){
           if((i>0 && arr[i]>arr[i-1])){
             vec[i]=vec[i-1]+1;
           }
        }
       for(int i=n-2;i>=0;i--){
         if(arr[i]>arr[i+1] && vec[i]<=vec[i+1]){
           vec[i]=vec[i+1]+1;
         }
         ans+=vec[i];
       }
       ans+=vec[n-1];
       return ans;
    }
};