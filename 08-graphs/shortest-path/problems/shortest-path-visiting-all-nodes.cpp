#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int poss = (1 << n);
        vector<vector<int>> dist(poss, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i{}; i < n; i++)
        {
            dist[1 << i][i] = 0;
            q.push({1 << i, i});
        }
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            int mask = tp.first;
            int node = tp.second;
            if (mask == ((1 << n) - 1))
                return dist[mask][node];
            for (auto &child : graph[node])
            {
                int newMask = mask | (1 << child);
                if (dist[newMask][child] == -1)
                {
                    dist[newMask][child] = dist[mask][node] + 1;
                    q.push({newMask, child});
                }
            }
        }
        return -1; // Not a connected component
    }
};

int main()
{
    Solution sol;

    // Example 1: [[1,2,3],[0],[0],[0]]
    vector<vector<int>> graph1 = {{1, 2, 3}, {0}, {0}, {0}};
    cout << "Shortest path length (graph1): "
         << sol.shortestPathLength(graph1) << endl; // Output: 4

    // Example 2: [[1],[0,2,4],[1,3,4],[2],[1,2]]
    vector<vector<int>> graph2 = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    cout << "Shortest path length (graph2): "
         << sol.shortestPathLength(graph2) << endl; // Output: 4

    return 0;
}
// 🔹 Variants of This Problem




// 1. Weighted Graph (shortest Hamiltonian walk)

// Change: If edges have weights instead of uniform 1, then normal BFS won’t work (since BFS assumes unit edge cost).

// Solution: Use Dijkstra’s algorithm on state (mask, node) instead of BFS.

// Priority queue instead of simple queue.

// dist[newMask][child] = min(dist[newMask][child], dist[mask][node] + weight(node, child)).

// This basically turns into Held–Karp style TSP dynamic programming solved with Dijkstra.




// 2. Hamiltonian Cycle (return to start)

// Instead of stopping when mask == (1<<n)-1, we must also return to the starting node.

// Condition: mask == (1<<n)-1 && node == start.

// Works the same way, just a different termination check.




// 3. Directed Graphs

// Exactly the same code works if the adjacency list is directed.

// Only difference: for(auto& child: graph[node]) will traverse directed edges instead of undirected ones.




// 4. Minimum steps to visit K specific nodes

// Instead of all nodes, only require visiting a given subset of nodes S.

// Then the target mask is targetMask = 0; for (v in S) targetMask |= (1<<v);.

// Stop when mask == targetMask.




// 5. Maximum collected value while visiting

// Suppose each node has a value (like coins).

// You want to maximize total value collected with a limited number of steps.

// State still (mask, node).

// Transition: update score dp[mask][node].

// Could use BFS (unweighted) or Dijkstra (weighted).




// 6. Shortest path covering edges (instead of nodes)

// Variant: must traverse every edge at least once (like a simplified Eulerian trail).

// Mask now represents visited edges, not nodes.

// Complexity increases (since edges > nodes usually), but principle is the same.




// 7. Constrained versions

// "Visit all nodes but only once" (Hamiltonian Path).

// Here, unlike original problem, you cannot revisit nodes.

// BFS with mask still works, but you cannot push if child is already visited.

// "Visit all nodes with at most k revisits" → add another dimension to state.





// 🔹 General Rule of Thumb

// Unweighted graph → BFS over (mask, node).

// Weighted graph → Dijkstra over (mask, node).

// We want all visited → check mask == (1<<n)-1.

// We want subset visited → check mask == targetMask.

// We want cycle → also check node == start.





// 👉 This exact state-compression trick is the foundation of:

// Travelling Salesman Problem (TSP)

// Minimum Steiner Tree (subset visiting problem)

// Robot vacuum cleaner problems (shortest path to clean all rooms)