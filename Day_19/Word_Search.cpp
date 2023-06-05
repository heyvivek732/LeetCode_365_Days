#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool solve(vector<vector<char>>&board,string word,int i,int j,int ind){
    if(ind==word.size()) return true;

    if(i<0 or j<0 or i==board.size() or j==board[0].size() or board[i][j]!=word[ind])return false;

    board[i][j]='-1';
    ind++;
    
   bool a=solve(board,word,i+1,j,ind);
   bool b=solve(board,word,i-1,j,ind);
   bool c=solve(board,word,i,j+1,ind);
   bool d=solve(board,word,i,j-1,ind);

   board[i][j]=word[ind-1];
   
  return a|| b || c|| d;
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    bool a=solve(board,word,i,j,0);
                    if(a) return a;
                }
            }
        }
        return false;
    }
};