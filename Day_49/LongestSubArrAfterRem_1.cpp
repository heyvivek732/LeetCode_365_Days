#include<bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
*/

// using TwoPointer Approach and Sliding Window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int j=0,zeroCnt=0,maxLen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zeroCnt++;
            while(zeroCnt>1){
                if(nums[j]==0)zeroCnt--;

                j++;
            }
            maxLen=max(maxLen,i-j+1-zeroCnt);
        }
        return maxLen==n?maxLen-1:maxLen;
    }
};
// Using Preficx and Suffix Sum
 int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        for(int i=1;i<n;i++){
            if(nums[i-1]==1)
            left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]==1)
            right[i]=right[i+1]+1;
        }
        int maxLen=0;
        for(int i=0;i<n;i++){
            maxLen=max(maxLen,left[i]+right[i]);
        }
        return maxLen;
    }