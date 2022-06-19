#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    int count = 0, candidate = 0;
    for(int i= 0; i < n; i++) {
        if(count == 0) {
            candidate = arr[i];
        }
        count += arr[i] == candidate ? 1 : -1;
    }
    count = 0;
    for(int i = 0; i < n; i++) {
        if(candidate == arr[i])
            count++;
    }
    return count > n/2  ? candidate : -1;
}
