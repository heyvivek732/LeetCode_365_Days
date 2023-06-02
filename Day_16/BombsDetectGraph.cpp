#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(vector<vector<int>>&gr,vector<bool>&vis,int &cnt,int &i){
    vis[i]=true;
    cnt++;
    for(int j=0;j<gr[i].size();++j){
        if(!vis[gr[i][j]]){
            dfs(gr,vis,cnt,gr[i][j]);           
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
       int res=0,sz=bombs.size();
       vector<vector<int>>gr(sz);
       for(int i=0;i<sz;i++){
           long long x1=bombs[i][0];
           long long y1=bombs[i][1];
           long long r1=bombs[i][2];

           for(int j=0;j<sz;j++){
               if(i!=j){
               long long x=abs(x1-bombs[j][0]),y=abs(y1-bombs[j][1]);
               if(x*x+y*y<=r1*r1){
                   gr[i].push_back(j);
                }
               }
           }
       } 
       res=INT_MIN;
       for(int i=0;i<sz;++i){
           int cnt=0;
           vector<bool>vis(sz,false);
           dfs(gr,vis,cnt,i);
           res=max(res,cnt);
       }
       return res;
    }
};