/*
Problem 0003: Longest Repeating Character Replacement

Description:
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


Constraints:

1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i{}, j{}, mx{}, ans{}, n = s.length();
        vector<int> freq(26, 0);
        while (j < n)
        {
            freq[s[j] - 'A']++;
            for (int p{}; p < 26; p++)
                mx = max(mx, freq[p]);
            // cout<<j<<" "<<mx<<endl;
            while ((j - i + 1 - mx) > k)
            {
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j - i + 1);
            // cout<<i<<" "<<j<<endl;
            // cout<<ans<<endl;
            j++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    
    return 0;
}
