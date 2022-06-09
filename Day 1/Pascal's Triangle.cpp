#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> ans;
    for(int i = 0; i < n; i++) {
        vector<long long int> v;
        if(i == 0) {
            v.push_back(1);
        }
        else {
            v.push_back(1);
            for(int i = 0; i < ans.back().size() - 1; i++) {
                v.push_back(ans.back()[i] + ans.back()[i+1]);
            }
            v.push_back(1);
        }
        ans.push_back(v);
    }
    return ans;
}
