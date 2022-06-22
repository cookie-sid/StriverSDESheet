#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    vector<int> chars(26, -1);
    int ans = 1, start = 0;
    for(int i = 0; i < input.length(); i++) {
        if(chars[input[i] - 'a'] != -1) {
            start = max(start,chars[input[i] - 'a'] + 1);
        }
        ans = max(ans, i - start + 1);
        chars[input[i] - 'a'] = i;
    }
    return ans;
}
