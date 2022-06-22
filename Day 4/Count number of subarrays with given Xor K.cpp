#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> m;
    m[0] = 1;
    int xo = 0, ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        int temp = x;
        if(i == 0) {
            xo = arr[i];
            temp = temp ^ xo;
            if(m[temp]) {
                ans += m[temp];
            }
        }
        else {
            xo = xo ^ arr[i];
            temp = temp ^ xo;
            if(m[temp]) {
                ans += m[temp];
            }
        }
        m[xo]++;
    }
    return ans;
}
