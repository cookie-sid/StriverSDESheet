#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;
    int dif = arr[0], numFound = 0;
    arr[arr[0] - 1] = -arr[arr[0] - 1];
    for(int i = 1; i < n; i++) {
        numFound = arr[i];
        if(arr[i] < 0)
            numFound = -arr[i];
        if(arr[numFound - 1] < 0) {
            ans.second = numFound;
        }
        else {
            arr[numFound - 1] = -arr[numFound - 1];
        }
        
        dif += arr[i] < 0 ? -arr[i]:arr[i];
        dif -= i;
    }
    dif -= n;
    ans.first = ans.second - dif;
    return ans;
}
