#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    int numToCheck = 0;
    for(int i = 0; i < n; i++) {
        numToCheck = arr[i];
        if(arr[i] < 0) {
            numToCheck = -arr[i];
        }
        if(arr[numToCheck] < 0) {
            return numToCheck;
        }
        else {
            arr[numToCheck] = -arr[numToCheck];
        }
    }
    
    return 0;
    
}
