#include <bits/stdc++.h>
using namespace std;


// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.


class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++)
        {
            for (int stop : routes[i])
            {
                stopToBuses[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q; // {stop, busesTaken}
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;

        q.push({source, 0});
        visitedStops.insert(source);

        while (!q.empty())
        {
            auto [stop, buses] = q.front();
            q.pop();

            if (stop == target)
                return buses;

            for (int bus : stopToBuses[stop])
            {
                if (visitedBuses.count(bus))
                    continue;
                visitedBuses.insert(bus);

                for (int nextStop : routes[bus])
                {
                    if (!visitedStops.count(nextStop))
                    {
                        visitedStops.insert(nextStop);
                        q.push({nextStop, buses + 1});
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