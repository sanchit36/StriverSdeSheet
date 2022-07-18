#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &arr, int n)
{
    int ans=arr[0];
    int mi=arr[0];
    int ma=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]<0) swap(mi, ma);
        ma=max(arr[i], arr[i]*ma);
        mi=min(arr[i], arr[i]*mi);
        ans=max(ma, ans);
    }
    return ans;
}
