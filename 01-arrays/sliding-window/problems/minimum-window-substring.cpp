/*
Problem 0002: Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(string s, string t)
    {
        unordered_map<char, int> freqt, freqs;
        for (auto &i : t)
            freqt[i]++;
        int n = s.length(), m = t.length(), i{}, j{}, ansi = -1, ansj = INT_MAX - 2;
        auto check = [&]() -> bool
        {
            for (auto &[i, j] : freqt)
            {
                if (freqs[i] < j)
                    return false;
            }
            return true;
        };
        while (j < n)
        {
            freqs[s[j]]++;
            if (check())
            {
                while (freqt[s[i]] < freqs[s[i]])
                {
                    freqs[s[i]]--;
                    i++;
                }
                if (j - i + 1 <= ansj - ansi + 1)
                {
                    ansi = i;
                    ansj = j;
                }
            }
            j++;
        }
        if (ansi == -1)
            return "";
        return s.substr(ansi, ansj - ansi + 1);
    }
};

int main() {
    Solution sol;
    
    // Test cases
    
    return 0;
}
