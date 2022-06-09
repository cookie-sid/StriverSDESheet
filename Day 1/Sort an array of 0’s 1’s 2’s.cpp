#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int start = 0, end = n - 1, ctr = 0;
    while(ctr <= end) {
        if(arr[ctr] == 1) {
            ctr++;
        }
        else if(arr[ctr] == 0) {
            arr[start++] = 0;
            ctr++;
        }
        else {
            while(end >= ctr and arr[end] == 2) {
                end--;
            }
            if(end > ctr and arr[end] == 1) {
                arr[end--] = 2;
            }
            else if(end > ctr and arr[end] == 0) {
                arr[start++] = 0;
                arr[end--] = 2;
            }
            ctr++;
        }
    }
    while(start <= end) {
        arr[start++] = 1;
    }
}