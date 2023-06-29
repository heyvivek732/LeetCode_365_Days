#include<bits/stdc++.h>
using namespace std;

/*
Input:
N = 8
Output:
10
Explanation:
Next happy number after 8 is 10 since
1*1 + 0*0 = 1
Example 2:

Input:
N = 10
Output
13
Explanation:
After 10, 13 is the smallest happy number because
1*1 + 3*3 = 10, so we replace 13 by 10 and 1*1 + 0*0 = 1.
*/

// Recursion 
bool isHappy(int n){
    int temp;
    int rem=0;
    int digit=6;
    while(digit){
        temp=0;
        while(n){
            rem=n%10;
            temp+=(rem*rem);
            n/=10;
        }
        if(temp==1)return true;
        digit--;
        n=temp;
    }
    return false;
}
    int nextHappy(int n){
       int low=n+1,high=100000;
        if(low>=high) return -1;
        if(isHappy(low)) return low;
        
        return nextHappy(low);
}

/*
iterative 
*/
bool isHappy(int n){
    int temp;
    int rem=0;
    int digit=6;
    while(digit){
        temp=0;
        while(n){
            rem=n%10;
            temp+=(rem*rem);
            n/=10;
        }
        if(temp==1)return true;
        digit--;
        n=temp;
    }
    return false;
}
    int nextHappy(int n){
       int low=n,high=100000;
       for(int i=low+1;i<high;i++){
         if(isHappy(i)){
             return i;
         }
       }
       return -1;
    }