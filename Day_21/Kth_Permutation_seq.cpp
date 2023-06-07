#include<bits/stdc++.h>
using namespace std;
/*
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Input: n = 3, k = 3
Output: "213"

*/

//Naive Approach  But got TLE
class Solution {
public:
void solve(int ind,string &temp,vector<string>&seq){
    if(ind==temp.size()){
        seq.push_back(temp);
        return;
    }
    for(int i=ind;i<temp.size();i++){
        swap(temp[i],temp[ind]);
        solve(ind+1,temp,seq);
        swap(temp[i],temp[ind]);
    }
}
    string getPermutation(int n, int k) {
        string temp="";
       for(int i=1;i<=n;i++){
            temp.push_back(i+'0');
       }
       vector<string>seq;
       solve(0,temp,seq);
       sort(seq.begin(),seq.end());
       return seq[k-1];
    }
};
// Optimal Approach Using Factorial
class Solution {
public:
    string getPermutation(int n, int k) {
       int fact=1;
       vector<int>num;
       for(int i=1;i<n;i++){
           fact=fact*i;
           num.push_back(i);
       }
       num.push_back(n);
       k=k-1;
       string ans="";
       while(true){
           ans+=to_string(num[k/fact]);
           num.erase(num.begin()+k/fact);
           if(num.size()==0){
               break;
           }
           k=k%fact;
           fact=fact/num.size();
       }
       return ans;
    }
};