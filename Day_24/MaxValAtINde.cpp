#include<bits/stdc++.h>
using namespace std;
//Binary Search +Greedy Algo

//nums.length == n
// nums[i] is a positive integer where 0 <= i < n.
// abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
// The sum of all the elements of nums does not exceed maxSum.
// nums[index] is maximized.
// Return nums[index] of the constructed array.

// Note that abs(x) equals x if x >= 0, and -x otherwise.
class Solution {
public:
long long check(int n,int ind,int a){
     int b=max(a-ind,0);
     long long res=(long long)(a+b)*(a-b+1)>>1;
     b=max(a-((n-1)-ind),0);
     res+=(long long)(a+b)*(a-b+1)>>1;
     return res-a;
}
    int maxValue(int n, int index, int maxSum) {
      maxSum-=n;
      int left=0,right=maxSum,mid;
      while(left<right){
          mid=(left+right+1)>>1;
          if(check(n,index,mid)<=maxSum) left=mid;
          else right=mid-1;
      }
      return left+1;
    }
};