#include<bits/stdc++.h>
using namespace std;

/*
Given a number in its binary form find if the given binary number is a multiple of 3. It is recommended to finish the task using one traversal of input binary number.

Example 1:

Input: S = "0011"
Output: 1
Explanation: "0011" is 3, which is divisible by 3.
Example 2:

Input: S = "100"
Output: 0
Explanation: "100"'s decimal equivalent is 4, which is not divisible by 3.
*/
int convertBinary(string s){
	    int ans=0;
	    int base=1;
	    for(int i=s.size()-1;i>=0;i--){
	        if(s[i]=='1'){
	            ans=(ans+base)%3;
	        }
	        base=(base<<1)%3;
	    }
	    return ans==0?1:0;
	}	
	int isDivisible(string s){
	   return convertBinary(s);
	}
