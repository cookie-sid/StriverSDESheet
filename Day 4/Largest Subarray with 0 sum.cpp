#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    
    unordered_map<int,int> m;
    m[0] = -1;
    int sum = 0, ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(m.find(sum) != m.end()) {
            ans = max(ans, i - m[sum]);
        }
        else {
            m[sum] = i;
        }
    }
    return ans;

}
