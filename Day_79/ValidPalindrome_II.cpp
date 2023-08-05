#include<bits/stdc++.h>
using namespace std;
/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Input: s = "eedede"
Output: true
Explanation: You could delete the character either 'e' && either 'd'.
*/
class Solution {
public:
bool isPalindrome(string s,int low,int high){
   while(low<high){
       if(s[low]==s[high]){
           low++;
           high--;
       }
       else return false;
   }
   return true;
}
    bool validPalindrome(string s) {
       int n=s.size();
       int low=0;
       int high=n-1;
       while(low<high){
           if(s[low]==s[high]){
               low++;
               high--;
           }else{
               return isPalindrome(s,low+1,high) || isPalindrome(s,low,high-1);
           }
       }
       return true;
    }
};