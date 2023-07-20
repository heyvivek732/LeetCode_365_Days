#include<bits/stdc++.h>
using namespace std;

/*

 Type : Stack
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.



Intuitions : -
     + -----> right side
     - <------ left side
 1st Move With sign if on of them are small then remove and move forward
 2nd if both are equal then remove both 
 3rd if all are remove them return remaining asteroids which destroyed all


*/
vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int  temp=0;
        for(int i=0;i<asteroids.size();i++){
            if( st.empty() || asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else {
                int temp=abs(asteroids[i]);
                while(!st.empty() && st.top()>0 && st.top()<temp){
                    st.pop();
                }
                if(!st.empty() && st.top()==temp){
                    st.pop();
                }else{
                    if(st.empty() || st.top()<0){
                        st.push(-temp);
                    }
                }
            }   
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }