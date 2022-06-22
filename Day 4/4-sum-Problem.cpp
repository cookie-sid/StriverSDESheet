#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    unordered_map<int,map<pair<int,int>,bool>> sums;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            sums[arr[i] + arr[j]][make_pair(i,j)] = true;
        }
    }
    int total = sums.size();
    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 1; j < n - 2; j++) {
            for(auto x : sums[target - arr[i] - arr[j]]) {
                if(x.first.first > j and x.first.second > j) {
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
