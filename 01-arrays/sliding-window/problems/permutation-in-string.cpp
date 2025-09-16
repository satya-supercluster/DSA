/*
Problem 0004: Permutation in String

Description:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        vector<int> freq1(26, 0), freq2(26, 0);
        for (auto &i : s1)
            freq1[i - 'a']++;
        int i{};
        for (int j{}; j < m; j++)
        {
            freq2[s2[j] - 'a']++;
            if (j < n - 1)
                continue;
            if (freq1 == freq2)
                return true;
            freq2[s2[i] - 'a']--;
            i++;
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    
    return 0;
}
