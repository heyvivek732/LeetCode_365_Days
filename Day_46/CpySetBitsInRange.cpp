#include<bits/stdc++.h>
using namespace std;

/*
X = 44, Y = 3 
L = 1,  R = 5
Output: 
47
Explaination: 
Binary represenation of 44 and 3 is 101100 and 000011. So in the range 1 to 5 there are two set bits of 3 (1st & 2nd position). If those are set in 44 it will become 101111 which is 47.
*/
     int setSetBit(int x, int y, int l, int r){
       for(int i=l;i<=r;i++){
           if(y &(1<<(i-1))){
               x=x|(1<<(i-1));
           }
       }
       return x;
    }