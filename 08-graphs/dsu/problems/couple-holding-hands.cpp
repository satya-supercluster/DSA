#include <bits/stdc++.h>
using namespace std;


// There are n couples sitting in 2n seats arranged in a row and want to hold hands.

// The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

// Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

 

// Example 1:

// Input: row = [0,2,1,3]
// Output: 1
// Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

// Example 2:

// Input: row = [3,2,0,1]
// Output: 0
// Explanation: All couples are already seated side by side.
 

// Constraints:

// 2n == row.length
// 2 <= n <= 30
// n is even.
// 0 <= row[i] < 2n
// All the elements of row are unique.



class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i{}; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionPair(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        unordered_map<int, int> node2pair;
        int n = row.size();
        for (int i{}; i < n; i += 2)
        {
            node2pair[row[i]] = i / 2;
            node2pair[row[i + 1]] = i / 2;
        }
        n /= 2;
        DisjointSet dsu = DisjointSet(n);
        for (int i{}; i < row.size(); i += 2)
        {
            int a = node2pair[i];
            int b = node2pair[i + 1];
            dsu.unionPair(a, b);
        }
        vector<int> compSize(n, 0);
        for (int i{}; i < n; i++)
        {
            compSize[dsu.findParent(i)]++;
            ;
        }
        int ans{};
        for (auto &i : compSize)
        {
            if (i)
                ans += i - 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    return 0;
}