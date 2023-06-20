#include<bits/stdc++.h>
using namespace std;
/*
Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
*/

/*
Explanation :
   N=9 ,k=3
   nums = [7,4,3,9,1,8,5,2,6]
           0  1  2  3  4  5  6  7  8
first ans  =  [-1,-1,-1,-1,-1,-1,-1,-1,-1];

int widow=2*k+1 => 2*3+1=7

0. sum+7=7;  if(i-l>=0) x
1. sum+4=11;  if(i-l>=0) x
2  sum+3=14   if(i-l>=0) x
3  sum+9=23  if(i-l>=0)  x
4  sum+1=24   if(i-l>=0) x
5  sum+8=32   if(i-l>=0) x
6  sum+5=37   if(i-l>=0)  x

But , if(i>=l-1){ ans[i-k]=sum/l; }  (i-k) => 6-3 =3
     [-1,-1,-1,3,-1,-1,-1,-1,-1]

7 sum+6=43  if(i-l>=0) sum-=nums[i-l]; (num[i-l] = 7-7=0)
          sum-=nums[0] = sum-7 =34
*/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long n=nums.size();
        long l=2*k+1;
        vector<int>ans(n,-1);
        long  sum=0;

        if(n<l) return ans;
        for(int i=0;i<n;++i){
            sum+=nums[i];

            if(i-l>=0){
                sum-=nums[i-l];  
            }
            if(i>=l-1){
               ans[i-k]=sum/l;
            }
        }
        return ans;
    }
};