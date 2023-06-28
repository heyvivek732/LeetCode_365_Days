#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Power Function 
int binaryExp(int a,int b){
    a=a%1337;
    int ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*1LL*a)%1337;
        }
        a=(a*1LL*a)%1337;
        b>>=1;
    }
    return ans;
}
    int superPow(int a, vector<int>& b) {
       int bmod=0;
       int etf=1140; // The Euler totient function value(1337) => 1140 (n*(1-1/p))
       for(auto it:b){
           bmod=(bmod*10+it)%1140;
       }
       return binaryExp(a,bmod);
    }
};