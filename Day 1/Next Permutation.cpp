#include <bits/stdc++.h>

void reverse(vector<int> &p, int start, int end) {
    int nums = end - start + 1;
    for(int i = start; i < (start + nums/2) ; i++) {
        int temp = p[i];
        p[i] = p[end - (i - start)];
        p[end - (i - start)] = temp;
    }
}

vector<int> nextPermutation(vector<int> &p, int n)
{
    int end = n - 1;
    while(end > 0 and p[end] < p[end - 1]) {
        end--;
    }
    if(end == 0) {
        reverse(p,0,n-1);
    }
    else {
        reverse(p,end,n - 1);
        for(int i = end; i < n; i++) {
            if(p[i] > p[end - 1]) {
                int temp = p[i];
                p[i] = p[end - 1];
                p[end - 1] = temp;
                break;
            }
        }
    }
    return p;
}