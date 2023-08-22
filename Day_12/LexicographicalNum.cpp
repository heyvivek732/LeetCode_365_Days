#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n){
    if(i>n) return;

    cout<<i<<" ";
    for(int j=0;j<10;j++){
       solve(10*i+j,n);
    }
}
int lexicographicalNumber(int n){
    for(int i=1;i<=9;i++){
        solve(i,n);
    }
}
int main(){
    int n;
    n=13;
    lexicographicalNumber(n);
}