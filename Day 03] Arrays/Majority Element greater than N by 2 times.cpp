#include <bits/stdc++.h>
// Solution 1(Brute Force) :

// Check the count of occurrences of all elements of the array one by one.Start from the first element of the array
// and count the number of times it occurs in the array.If the count is greater than the floor of N / 2 then return that element as the answer.If not,
// proceed with the next element in the array and repeat the process.
// Time Complexity : O(N2)
//  Space Complexity : O(1)

// Solution 2 (Better):
// Frequency Method:
// Time Complexity: O(n), Space Complexity: O(n)
int findMajorityElement(int arr[], int n)
{
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        if (freq[arr[i]] > floor(n / 2))
            return arr[i];
    }
    return -1;
}

// Solution 3 (Optimal):
// Moore’s Voting Algorithm
// Time Complexity: O(n), Space Complexity: O(1)
/*
Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.

Now, we can say that count of minority elements and majority element are equal upto certain point
of time in the array. So when we traverse through the array we try to keep track of the count of
elements and which element we are tracking.
Since the majority element appears more than N/2 times, we can say that at some point in
array traversal we find the majority element.
*/

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int candidate = 0;
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        if (num == candidate)
            count += 1;
        else
            count -= 1;
    }
    return candidate;
}

int findMajorityElement(int arr[], int n)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
        }
        if (arr[i] == candidate)
            count += 1;
        else
            count -= 1;
    }
    return candidate;
}