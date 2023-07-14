#include<bits/stdc++.h>
using namespace std;
/*
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
Example 3:

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 

Constraints:

1 <= arr.length <= 105
-104 <= arr[i], difference <= 104
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
      unordered_map<int,int>mp;
      int len=0;
      for(auto it:arr){
          len=max(len,mp[it]=1+mp[it-diff]);
      }
        return len;
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
      unordered_map<int,int>mp;
      int ans=0;
      for(int i=0;i<arr.size();i++){
          int temp=arr[i];
          if(mp.find(temp-diff)!=mp.end()){
              mp[temp]=1+mp[temp-diff];
          }else{
              mp[temp]=1;
          }
          ans=max(ans,mp[temp]);
      }
      return ans;
    }
};