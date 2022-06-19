#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int start = 0, end = m - 1, row = -1;
    while(start <= end) {
        int mid = (start + end)/2;
        if(mat[mid][0] == target) {
            return true;
        }
        else if(mat[mid][0] > target) {
            if(mid > 0 and mat[mid - 1][0] < target) {
                row = mid - 1;
                break;
            }
            else if(mid == 0) {
                return false;
            }
            else {
                end = mid - 1;
            }
        }
        else {
            start = mid + 1;
        }
    }
    if(row == -1) {
        row = m - 1;
    }
    int temp = lower_bound(mat[row].begin(),mat[row].end(),target) - mat[row].begin();
    if(temp >= n) {
        return false;
    }
    return mat[row][temp] == target;
}
