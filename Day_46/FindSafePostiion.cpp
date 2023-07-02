#include<bits/stdc++.h>
using namespace std;
// Josephus Problem 
/*
Input:
n = 2, k = 1
Output:
2
Explanation:
Here, n = 2 and k = 1, then safe position is
2 as the person at 1st position will be killed.
*/    
 int safePos(int n, int k) {
       if(n==1)return 1;
       int x=(safePos(n-1,k)+k)%n;
       return x==0?n:x;
    }