#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum = max(sum + arr[i], (long long)arr[i]);
        ans = max(sum,ans);
    }
    ans = max(ans,0LL);
    return ans;
}