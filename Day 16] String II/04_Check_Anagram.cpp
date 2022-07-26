#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string &str1, string &str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

// Using hashing
// make 2 hash array for the string of size of alphabets
// check for each index if they are equal or not

// Using single hash
// make 1 hash array for the string
// for the first string inc the freq of alphabets
// for the second string dec the freq of alphabets
// if at last all are zeros anagram else not