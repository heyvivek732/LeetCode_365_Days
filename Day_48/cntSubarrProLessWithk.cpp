#include<bits/stdc++.h>
using namespace std;
/*
Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
*/

// Brute Force Approach
 int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
       long long cnt=0;
       for(int i=0;i<n;i++){
        long long currSum=1;
         for(int j=i;j<n;j++){
             currSum*=a[j];
             if(currSum<k)cnt++;
             else break;
         }
           
       }
       return cnt;
    }
// Otpimal
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
      long long cnt=0;
      long long prod=1;
      long long left=0;
      for(int i=0;i<n;i++){
          prod*=a[i];
          while(prod>=k && left<=i){
              prod/=a[left++];
          }
          cnt+=i-left+1;
      }
      return cnt;
    }