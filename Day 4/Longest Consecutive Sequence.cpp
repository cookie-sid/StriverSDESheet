#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> s;
    for(auto x : arr) {
        s.insert(x);
    }
    int ans = 1;
    for(auto x : arr) {
        if(!s.count(x - 1)) {
            int currLen = 1;
            int currNum = x;
            while(s.count(currNum + 1)) {
                currLen++;
                currNum++;
            }
            ans = max(ans,currLen);
        }
    }
    return ans;
}
