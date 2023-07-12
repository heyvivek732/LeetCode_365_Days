#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getRow(int n) {
       vector<int>ans;
       long long res=1;
       ans.push_back(res);
       for(int i=1;i<=n;i++){
         res+=res*(n-i);
         res=res/(i);
         ans.push_back(res);
       } 
       return ans;
    }
};