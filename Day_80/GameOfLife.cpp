#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int count_neighbours(vector<vector<int>>&board,int i,int j,int n,int m){
     int live=0;
     if(j>0){
     if(board[i][j-1]==1)live++;
     }
     if(j<m-1){
     if(board[i][j+1]==1)live++;
     }
     if(i>0){
     if(board[i-1][j]==1)live++;
     }
     if(i<n-1){
     if(board[i+1][j]==1)live++;
     }
     if(i>0 && j>0){
     if(board[i-1][j-1]==1)live++;
     }
     if(i<n-1 && j<m-1){
     if(board[i+1][j+1]==1)live++;
     }
     if(i<n-1 && j>0){
     if(board[i+1][j-1]==1)live++;
     }
     if(i>0 && j<m-1){
     if(board[i-1][j+1]==1)live++;
     }
     return live;
 }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>dup = board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=count_neighbours(dup,i,j,n,m);
                if(board[i][j]==0){
                    if(a==3){
                        board[i][j]=1;
                    }
                }
                else if(board[i][j]==1){
                    if(a<2 || a>3){
                        board[i][j]=0;
                    }
                }
            }
        }
    }
};