#include <bits/stdc++.h> 

void merge(long long *arr, int start, int mid, int end, long long &ans) {
    vector<long long> temp(end - start + 1);
    int st = 0, lstart = start, rstart = mid + 1, lnums = mid - start + 1;
    int rnums = end - start + 1 - lnums;
    while(lstart <= mid and rstart <= end) {
        if(arr[lstart] > arr[rstart]) {
            temp[st++] = arr[rstart++];
            ans += lnums - (lstart - start);
        }
        else {
            temp[st++] = arr[lstart++];
        }
    }
    while(rstart <= end) {
        temp[st++] = arr[rstart++];
    }
    while(lstart <= mid) {
        temp[st++] = arr[lstart++];
    }
    st = 0;
    for(int i = start; i <= end; i++) {
        arr[i] = temp[st++];
    }
}

void mergeSort(long long *arr, int start, int end, long long &ans) {
    if(start == end) {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr, start, mid, ans);
    mergeSort(arr,mid + 1, end, ans);
    merge(arr,start,mid,end, ans);
}

long long getInversions(long long *arr, int n){
    long long ans = 0;
    mergeSort(arr,0,n-1,ans);
    return ans;
}
