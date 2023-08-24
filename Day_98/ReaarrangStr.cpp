#include<bits/stdc++.h>
using namespace std;
string reorganizeString(string s) {
     int n=s.size();
     string ans="";
     unordered_map<char,int>mp;
     for(auto it:s)mp[it]++;
     priority_queue<pair<int,char>>pq;
     for(auto it:mp){
         if(it.second>(n+1)/2)return "";
         else{
           pq.push({it.second,it.first});
         }
     }
     while(pq.size()>=2){
         auto [a,c]=pq.top();
         pq.pop();
         auto [b,ch]=pq.top();
         pq.pop();
        ans+=c;
        ans+=ch;
        if(--a>0)pq.push({a,c});
        if(--b>0)pq.push({b,ch});
     }
     if(pq.size()>0){
         auto [a,b]=pq.top();
         if(a>1)return "";
        ans+=b;
     }
     return ans;
}