#include <bits/stdc++.h>
using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &rack, int n) {
    vector<int> dp(n, 0);
    dp[n-1] = rack[n-1];
    int maxi = dp[n-1];
    for(int ind=n-2;ind>=0;ind--) {
        dp[ind] = rack[ind];
        for(int prev=n-1;prev>ind;prev--) {
            if((rack[prev] > rack[ind])
               && (rack[ind] + dp[prev] > dp[ind])) {
                dp[ind] = rack[ind] + dp[prev];
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}