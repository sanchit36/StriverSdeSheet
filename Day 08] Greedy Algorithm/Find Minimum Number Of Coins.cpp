int findMinimumCoins(int amount)
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    int countCoins;

    for (int i = n - 1; i >= 0; i--)
    {
        if (amount >= coins[i])
        {
            countCoins += amount / coins[i];
            amount %= coins[i];
        }
    }
    return countCoins;
}
