#include<bits/stdc++.h>
using namespace std;
string Longest_palidrom_sub(string s){
    if(s.empty()) return "";
    if(s.size()==1) return s;
    int mini=0,maxi=1;
    int i=0;
    while(i<s.size()){
        if(s.size()-i<=maxi>>1) break;

        int  j=i,k=i;
        while(k<s.size()-1 && s[k+1]==s[k])++k;

     i=k+1;

     while(k<s.size()-1 && j>0 && s[k+1]==s[j-1]){
        k++;
        j--;
     }
     int n=k-j+1;
     if(n>maxi){
        mini=j;
        maxi=n;
     }
    }
    return s.substr(mini,maxi);
}
int main(){
    string s="aaaaeeeedddddccccddddeeeeaaaaaaaa";
    cout<<"The maxi Palidrome Substring are : "<<Longest_palidrom_sub(s)<<endl;
}