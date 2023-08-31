#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
class Node{
    public:
    int  key,val;
    Node *prev;
    Node *next;
    Node(int _key,int _val){
        key=_key;
        val=_val;
    }
  };
 Node *head= new Node(-1,-1);
 Node *tail=new Node(-1,-1);
 int cap;
 unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
 void addNode(Node *newNode){
    Node *temp=head->next;;
    newNode->next=temp;
    newNode->prev=head;
    head->next=newNode;
    temp->prev=newNode;
 }
 void deleteNode(Node *del){
     Node *temp=del->prev;
     Node *temp1=del->next;
     temp->next=temp1;
     temp1->prev=temp;
 }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *temp=mp[key];
            int res=temp->val;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);

            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */