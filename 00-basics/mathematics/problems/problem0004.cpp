/*
Problem 0004: Fast Exponentiation

Description:
Implement binary exponentiation to calculate (base^exp) % mod efficiently in O(log n) time.

Difficulty: Medium
Topics: Mathematics

Time Complexity: O(log n)
Space Complexity: O(log n)) due to recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve fast_exponentiation
    int power(int x,int y){
        int res=1;
        while(y){
            if(y&1) res=(res*x);
            y>>=1;
            x=(x*x);
        }
        return res;
    }
    void solve(int x,int y) {
        // Implementation here
        cout<<power(x,y)<<endl;  
    }
};

int main() {
    Solution sol;
    
    // Test cases
    sol.solve(2,10); // 1024
    sol.solve(3,5);  // 243 
    sol.solve(5,3);  // 125
    return 0;
}
