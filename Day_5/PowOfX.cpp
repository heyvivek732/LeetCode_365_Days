#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//First Approach
double myPow(double x, int n) {
        double ans=0;
        ans=pow(x,n);
        return ans;
}

//Second Approach
long long myPow(long long x,long long n){
    if(n==0) return 1;
    long long ans=myPow(x,n/2);
    ans*=ans;
    ans%=mod;
    if(n%2==1){
        ans=ans*x;
    }
    ans%=mod;
    return ans;
}

//Third Most Optimal
 double myPow(double x, int n) {
        double ans=1.0;
        long n1=n;
        if(n1<0) n1=-1*n1;
        while(n1>0){
            if(n1%2==1){
                ans=ans*x;
                n1=n1-1;
            }
            else{
                x=x*x;
                n1>>=1;
            }
        }
        if(n<0) ans=double(1.0)/double(ans);
        return ans;
    }