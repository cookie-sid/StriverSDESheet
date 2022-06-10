#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    
    int end1 = m - 1, end2 = n - 1, last = m + n - 1;
    while(end1 >= 0 and end2 >= 0) {
        if(arr1[end1] > arr2[end2]) {
            arr1[last--] = arr1[end1--];
        }
        else {
            arr1[last--] = arr2[end2--];
        }
    }
    while(end1 >= 0) {
        arr1[last--] = arr1[end1--];
    }
    while(end2 >= 0) {
        arr1[last--] = arr2[end2--];
    }
    return arr1;
}
