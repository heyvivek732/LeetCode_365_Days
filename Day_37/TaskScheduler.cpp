#include<bits/stdc++.h>
using namespace std;

// Task Scheduler  O(nlong) SC:O(2n)
/*
Input:
N = 6
K = 2
task[ ] = {'A', 'A', 'A', 'B', 'B', 'B'}
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is atleast 2 units of time between any two same tasks.

  A-> 3
  B -> 3
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      unordered_map<char,int>mp;
      for(auto it:tasks)mp[it]++;

      priority_queue<int>pq;
      for(auto it:mp) pq.push(it.second);
    int res=0;
      while(!pq.empty()){
          int time=0;
          vector<int>temp;
          for(int i=0;i<n+1;i++){
              if(!pq.empty()){
                  temp.push_back(pq.top()-1);
                  pq.pop();
                  time++;
              }
          }
          for(auto it:temp){
              if(it)pq.push(it);
          }
          res+=pq.empty()?time:n+1;
      }
      return res;
    }
};

// Optimal hashTable TC:0(n) SC :O(1)
    class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     vector<int>freq(26,0);
     for(auto it:tasks) freq[it-'A']++;

     sort(freq.begin(),freq.end());
     int m=freq[25];
     int idl=(m-1)*n;

     for(int i=24;i>=0;i--){
      idl-=min(m-1,freq[i]);
     }  
     idl=max(0,idl);
     return idl+tasks.size();
    }
};