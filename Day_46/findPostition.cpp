#include<bits/stdc++.h>
using namespace std;
/*
Input: n = 5
Output: 4 
Explanation: 1,2,3,4,5 -> 2,4 -> 4.

Example 2:

Input: n = 9
Output: 8
Explanation: 1,2,3,4,5,6,7,8,9
->2,4,6,8 -> 4,8 -> 8. 
*/
 long long int nthPosition(long long int n){
      if(n==1)return 1;
      return nthPosition(n/2)*2;
    }