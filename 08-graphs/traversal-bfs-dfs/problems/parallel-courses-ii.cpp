#include <bits/stdc++.h>
using namespace std;

// You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.

// In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.

class Solution
{
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k)
    {
        vector<int> pre(n, 0);
        for (auto &r : relations)
        {
            pre[r[1] - 1] |= (1 << (r[0] - 1));
        }

        vector<int> dist(1 << n, -1);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int mask = q.front();
            q.pop();
            if (mask == (1 << n) - 1)
                return dist[mask];

            int available = 0;
            for (int i = 0; i < n; i++)
            {
                if (((mask >> i) & 1) == 0 && ((mask & pre[i]) == pre[i]))
                {
                    available |= (1 << i);
                }
            }

            if (__builtin_popcount(available) <= k)
            {
                int newmask = mask | available;
                if (dist[newmask] == -1)
                {
                    dist[newmask] = dist[mask] + 1;
                    q.push(newmask);
                }
            }
            else
            {
                for (int subset = available; subset; subset = (subset - 1) & available)
                {
                    if (__builtin_popcount(subset) == k)
                    {
                        int newmask = mask | subset;
                        if (dist[newmask] == -1)
                        {
                            dist[newmask] = dist[mask] + 1;
                            q.push(newmask);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    return 0;
}






// More->
// picks for practicing mask-based DP/BFS:

// 847. Shortest Path Visiting All Nodes

// 943. Find the Shortest Superstring

// 1349. Maximum Students Taking Exam

// 1879. Minimum XOR Sum of Two Arrays

// 698. Partition to K Equal Sum Subsets

// Maximum AND Sum of Array(LeetCode 2172)

// Minimum Number of Increments on Subarrays to Form a Target Array(LeetCode 1674)