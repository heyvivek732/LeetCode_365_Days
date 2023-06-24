#include<bits/stdc++.h>
using namespace std;
/*
Input:
n = 6
arr[] = {“abba”, “abbb”, “abbc”, “abbd”, 
“abaa”, “abca”}
str = “abbg”
k = 3
Output: 
4 
Explanation:
“abba”, “abbb”, “abbc” and “abbd” have their prefix of length 3 equal to 3-length prefix of str i.e., "abb".

*/
// Approach 1st
int findpref(string s,int k,string str){
    for(int i=0;i<k;i++){
        if(s[i]!=str[i]) return 0;
    }
    return 1;
}
    int klengthpref(string arr[], int n, int k, string str){   
        int cnt=0;
        for(int i=0;i<n;i++){
            int ans=findpref(arr[i],k,str);
            cnt+=ans;
        }
        return cnt;
}
// Approach 2nd
 int klengthpref(string arr[], int n, int k, string str){  
        if(k>str.size()) return 0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i].substr(0,k)==str.substr(0,k)) cnt++;
            
        }
        return cnt;
 }
