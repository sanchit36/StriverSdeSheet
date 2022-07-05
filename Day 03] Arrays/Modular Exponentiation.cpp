#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m)
{
    //     a*b%c = (a%c*b%c)%c
    long ans = 1;
    long xx = x;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            // even power
            xx = (xx % m * xx % m) % m;
            n = n / 2;
        }
        else
        {
            // odd power
            ans = (ans % m * xx % m) % m;
            n = n - 1;
        }
    }
    return (int)(ans % m);
}