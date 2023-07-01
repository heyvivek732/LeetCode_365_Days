#include<bits/stdc++.h>
using namespace std;
/*
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
*/
void Solve(vector<int>&arr,int i){
    int n=arr.size();
    int rem=0;
    int fact;
    for(int j=0;j<n;j++){
        fact=arr[j]*i;
        fact+=rem;
        arr[j]=fact%10;
        rem=fact/10;
    }
    while(rem>0){
        arr.push_back(rem%10);
        rem/=10;
    }
}
    vector<int> factorial(int N){
      vector<int>fact;
      fact.push_back(1);
       for(int i=2;i<=N;i++){
          Solve(fact,i);
       }
       
       reverse(fact.begin(),fact.end());
       return fact;
    }