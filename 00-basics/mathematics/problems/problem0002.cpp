/*
Problem 0002: Prime Numbers

Description:
Check if a number is prime, generate prime numbers using Sieve of Eratosthenes, find prime factorization.

Difficulty: Medium
Topics: Mathematics

Time Complexity: O(n log(log(n))) for Sieve of Eratosthenes
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<bool> isPrime;
    int size;
    // Function to solve prime_numbers
    void sieve(int n)
    {
        size = n;
        isPrime.resize(size + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= size; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j <= size; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    bool solve(int x)
    {
        // Implementation here
        if (x > size)
        {
            throw invalid_argument("Number exceeds the limit set by sieve");
        }
        return isPrime[x];
    }
};

int main()
{
    Solution sol;

    // Test cases
    int max, x;
    cin >> max >> x;
    if (max < 2)
    {
        cout << "There are no prime numbers less than 2" << endl;
        return 0;
    }
    sol.sieve(max);
    try
    {
        if (sol.solve(x))
            cout << x << " is a prime number" << endl;
        else
            cout << x << " is not a prime number" << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
