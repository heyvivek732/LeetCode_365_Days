#include<bits/stdc++.h>
using namespace std;
/*
 -> Priorty Queue TwoPointer Approaches

 Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
*/
long long totalCost(vector<int>& costs, int k, int c) {
        long long ans=0;
        int n=costs.size();
      priority_queue <int, vector<int>, greater<int> > first;
      priority_queue <int, vector<int>, greater<int> > last;
    int cnt=0;
    int low=0,high=n-1;
    while(cnt<k){
          while(first.size()<c && low<=high){
              first.push(costs[low++]);
          }
          while(last.size()<c && high>=low){
              last.push(costs[high--]);
          }

          int a=first.size()>0?first.top():INT_MAX;
          int b=last.size()>0?last.top():INT_MAX;

          if(a<=b){
              ans+=a;
              first.pop();
          }else{
              ans+=b;
              last.pop();
          }
          cnt++;
    }
    return ans;
    }