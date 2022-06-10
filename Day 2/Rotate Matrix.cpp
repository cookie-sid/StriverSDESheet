#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int vertStart = 0, vertEnd = n - 1;
    int horStart = 0, horEnd = m - 1;
    int countOps = 0;
    while(horStart < horEnd and vertStart < vertEnd) {
        int temp = mat[vertStart][horStart];
        for(int i = horStart + 1; i <= horEnd and countOps < n * m; i++) {
            int tt = mat[vertStart][i];
            mat[vertStart][i] = temp;
            temp = tt;
            countOps++;
        }
        for(int i = vertStart + 1; i <= vertEnd and countOps < n * m; i++) {
            int tt = mat[i][horEnd];
            mat[i][horEnd] = temp;
            temp = tt;
            countOps++;
        }
        for(int i = horEnd - 1; i >= horStart and countOps < n * m; i--) {
            int tt = mat[vertEnd][i];
            mat[vertEnd][i] = temp;
            temp = tt;
            countOps++;
        }
        for(int i = vertEnd - 1; i >= vertStart and countOps < n * m; i--) {
            int tt = mat[i][horStart];
            mat[i][horStart] = temp;
            temp = tt;
            countOps++;
        }
        vertStart++;
        horStart++;
        vertEnd--;
        horEnd--;
    }
}
