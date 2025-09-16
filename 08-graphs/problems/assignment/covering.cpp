#include <bits/stdc++.h>
using namespace std;

/*

Problem Statement

    We are given two groups of points:

    Group1 size = m

    Group2 size = n

    cost[i][j] = cost to connect ith point in Group1 to jth point in Group2.

    We must connect every point in both groups to at least one point in the other group.
    Return the minimum total cost./

*/


class Solution
{
public:
    int connectTwoGroups(vector<vector<int>> &cost)
    {
        int m = cost.size();
        int n = cost[0].size();
        int FULL = (1 << n);
        const int INF = 1e9;

        vector<vector<int>> dp(m + 1, vector<int>(FULL, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int mask = 0; mask < FULL; mask++)
            {
                if (dp[i - 1][mask] == INF)
                    continue;
                for (int j = 0; j < n; j++)
                {
                    int newMask = mask | (1 << j);
                    dp[i][newMask] = min(dp[i][newMask],
                                         dp[i - 1][mask] + cost[i - 1][j]);
                }
            }
        }

        // Now ensure every group2 point is covered
        int ans = INF;
        for (int mask = 0; mask < FULL; mask++)
        {
            if (dp[m][mask] == INF)
                continue;

            // Add cost to cover any missing group2 points
            int extra = 0;
            for (int j = 0; j < n; j++)
            {
                if (!(mask & (1 << j)))
                {
                    int best = INF;
                    for (int i = 0; i < m; i++)
                    {
                        best = min(best, cost[i][j]);
                    }
                    extra += best;
                }
            }
            ans = min(ans, dp[m][mask] + extra);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    return 0;
}