#include <bits/stdc++.h>

// Sort the array and if index i and i+1 are same, then return arr[i]
// Time Complexity: O(nlogn) + O(n), Space Complexity: O(1)
int findDuplicate(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return arr[i];
    }
    return -1;
}

// Frequency Array Method
// Time Complexity: O(n), Space Complexity: O(n)
int findDuplicate(int arr[], int n)
{
    int freq[n];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        if (freq[arr[i]] == 2)
            return arr[i];
    }
    return -1;
}

// Tortoise Method
// Intuition: Tortoise method is a method of finding the duplicate element in an array.
// We keep a slow and fast pointer. The slow pointer moves one step at a time and the fast pointer moves two steps at a time.
// If the slow pointer ever catches up with the fast pointer, then the duplicate element is present.
// Point Faster Pointer to the head of the list. Loop Until the pointers meet.
// Time Complexity: O(n), Space Complexity: O(1)
int findDuplicate(vector<int> &arr, int n)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
