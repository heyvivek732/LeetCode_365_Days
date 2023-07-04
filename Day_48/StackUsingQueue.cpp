#include<bits/stdc++.h>
using namespace std;
class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() { 
    }
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
       if(q1.empty())return -1;
       int val=q1.front();
       q1.pop();
       return val; 
    }
    
    int top() {
       return q1.front(); 
    }
    
    bool empty() {
        if(q1.empty())return true;
        return false;
    }
};
