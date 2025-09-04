/*
Problem 0001: GCD and LCM

Description:
Find Greatest Common Divisor and Least Common Multiple of two or more numbers using Euclidean algorithm.

Difficulty: Medium
Topics: Mathematics

Time Complexity: O(log(min(x,y)))
Space Complexity: O(log(min(x,y))) due to recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to solve gcd_and_lcm
    int gcd(int x, int y)
    {
        if (y < x)
            swap(x, y);
        if (x == 0)
            return y;
        return gcd(y % x, x);
    }

    int lcm(int x, int y)
    {
        int gcd_val = this->gcd(x, y);
        if (gcd_val == 0)
            return 0;
        return (x * y) / gcd_val;
    }

public:
    void solve(int x, int y)
    {
        // Implementation here
        int lcm_val = this->lcm(x, y);
        int gcd_val = this->gcd(x, y);
        cout << "GCD of " << x << " and " << y << " is: " << gcd_val << endl;
        cout << "LCM of " << x << " and " << y << " is: " << lcm_val << endl;
    }
};

int main()
{
    Solution sol;

    // Test cases
    int x, y;
    cin >> x >> y;
    sol.solve(x, y);

    return 0;
}


// 4 12
// GCD of 4 and 12 is: 4
// LCM of 4 and 12 is: 12

// 12 28
// GCD of 12 and 28 is: 4
// LCM of 12 and 28 is: 84