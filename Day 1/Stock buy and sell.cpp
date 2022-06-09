#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int minTillNow = prices[0], ans = 0;
    for(int i = 0; i < prices.size(); i++) {
        ans = max(prices[i] - minTillNow, ans);
        minTillNow = min(minTillNow, prices[i]);
    }
    return ans;
}