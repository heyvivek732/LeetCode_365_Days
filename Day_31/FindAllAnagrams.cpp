#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach (sliding Window Approches)

/*
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
class Solution {
public:
 bool isAnagram(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size();
    int window = p.size();
    int i = 0, j = 0;

    while (j < n) {
        if (j - i + 1 < window) {
            j++;
        } else {
            if (isAnagram(s.substr(i, window), p)) {
                ans.push_back(i);
            }
            i++;
            j++;
        }
    }

    return ans;
  }
};
//Optimal  Approches (HashTable ,Sliding_window)
class Solution {
public:

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size();
    int window = p.size();
    
    if(s.size()<p.size()) return {};
    vector<int>hash_s(26,0);
    vector<int>hash_p(26,0);
    
    for(int i=0;i<window;i++){
        hash_p[p[i]-'a']++;
        hash_s[s[i]-'a']++;
    }
    
    if(hash_s==hash_p) ans.push_back(0);
    
    for(int i=window;i<n;i++){
        hash_s[s[i-window]-'a']--;
        hash_s[s[i]-'a']++;
        
        if(hash_s==hash_p) ans.push_back(i-window+1);
    }
    return ans;
  }
};