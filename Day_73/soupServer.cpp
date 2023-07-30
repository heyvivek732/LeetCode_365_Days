#include<bits/stdc++.h>
using namespace std;

/*
    Serve 100 ml of soup A and 0 ml of soup B,
Serve 75 ml of soup A and 25 ml of soup B,
Serve 50 ml of soup A and 50 ml of soup B, and
Serve 25 ml of soup A and 75 ml of soup B.
*/
class Solution {
public:
  double solve(int a,int b,map<pair<int,int>,double>&mp){
      if(a<=0 && b<=0)return 0.5;
      if(a<=0)return 1;
      if(b<=0)return 0;
      if(mp.count({a,b}))return mp[{a,b}];

      double ans=0;
      ans+=solve(a-100,b,mp);
      ans+=solve(a-75,b-25,mp);
      ans+=solve(a-50,b-50,mp);
      ans+=solve(a-25,b-75,mp);

      return mp[{a,b}]=double(ans)/(double)4;
  }
    double soupServings(int n) {
      if(n>=4800)return 1;
      map<pair<int,int>,double>mp;
      return solve(n,n,mp);   
    }
};