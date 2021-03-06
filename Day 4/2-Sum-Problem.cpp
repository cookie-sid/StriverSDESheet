#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    unordered_map<int,int> m;
    vector<vector<int>> ans;
    for(auto x : arr) {
        if(m[s - x] > 0) {
            for(int i = 0; i < m[s-x]; i++) {
                ans.push_back({min(x,s-x),max(x,s-x)});
            }
        }
        m[x] += 1;
    }
    sort(ans.begin(),ans.end());
    return ans;
}

//LC

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end())
                return {m[target - nums[i]],i};
            
            m[nums[i]] = i;
        }
        return {0,0};
    }
};
