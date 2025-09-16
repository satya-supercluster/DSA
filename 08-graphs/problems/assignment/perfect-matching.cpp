#include <bits/stdc++.h>
using namespace std;

/*
 Hungarian Algorithm
 -------------------
 Solves the Assignment Problem:
 - Given cost matrix cost[n][n], assigns each worker to exactly one job
   such that total cost is minimized.
 - Runs in O(n^3).
*/

const int INF = 1e9;

int hungarian(const vector<vector<int>> &cost)
{
    int n = cost.size();
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);

    for (int i = 1; i <= n; i++)
    {
        p[0] = i; // current row
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false);

        do
        {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;
            for (int j = 1; j <= n; j++)
            {
                if (!used[j])
                {
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; j++)
            {
                if (used[j])
                {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else
                {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        // Augmenting path reconstruction
        do
        {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    // Matching result is in p
    vector<int> assignment(n + 1);
    for (int j = 1; j <= n; j++)
    {
        assignment[p[j]] = j;
    }

    // Compute optimal cost
    int costAns = -v[0];
    cout << "Optimal assignment:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Worker " << i << " -> Job " << assignment[i]
             << " (Cost = " << cost[i - 1][assignment[i] - 1] << ")\n";
    }
    cout << "Minimum total cost = " << costAns << "\n";
    return costAns;
}

int main()
{
    // Example cost matrix
    vector<vector<int>> cost = {
        {4, 1, 3},
        {2, 0, 5},
        {3, 2, 2}};

    hungarian(cost);
    return 0;
}
