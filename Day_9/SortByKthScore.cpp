#include<bits/stdc++.h>
using namespace std;

//First Approaches With MaxHeap

/*
here is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.

You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.

Return the matrix after sorting it.

 Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
Explanation: In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
- The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
- The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.
*/
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int ind=0;
        vector<vector<int>>ans;
        int n=score.size(),m=score[0].size();
        
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i][k],i});
        }

        while(!pq.empty()){
            int row=pq.top().second;
            pq.pop();
            ans.push_back(score[row]);
        }
        return ans;
    }
// Second Approaches With Comparea Function
int k1;
bool comp(vector<int>&a,vector<int>&b){
    return a[k1]>b[k1];
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
       
       k1=k;
       sort(score.begin(),score.end(),comp);
       return score;
    }
};

// Third Approaches With compare But conzieces 

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
       
      sort(score.begin(),score.end(),[&](auto const &a,auto const &b){
          return a[k]>b[k];
      });
      return score;
    }
};