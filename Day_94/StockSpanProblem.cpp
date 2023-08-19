#include<bits/stdc++.h>
using namespace std;
/*
Solved By Using Previous Smaller Element 

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
*/
class StockSpanner {
public:
  stack<pair<int,int>>st;
  int i=0;
    StockSpanner() {
    }
    
    int next(int price) {
       if(st.empty()){
           st.push({price,i++});
           return 1;
       } else{
           while(!st.empty() && st.top().first<=price)st.pop();
        
          int ans =(st.empty())?i+1:i-st.top().second;

           st.push({price,i++});
           return ans;
       }
    }
};