#include<bits/stdc++.h>
using namespace std;
// Using Inbuilt funtion
class Solution {
public:
    vector<int> countBits(int n) {
       vector<int>ans;
       for(int i=0;i<=n;i++){
           ans.push_back(__builtin_popcount(i));
       } 
       return ans;
    }
};
// iterative Solution 
class Solution {
public:
    vector<int> countBits(int n) {
       vector<int>ans(n+1,0);
        int cnt=0;
       for(int i=1;i<=n;i++){
           int num=i;
           while(num>0){ 
               if(num&1==1)cnt++;
               num>>=1;
           }
           ans[i]=cnt;
           cnt=0;
       } 
       return ans;
    }
};