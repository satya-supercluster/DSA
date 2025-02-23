#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;
const bool TestCases = false;
const int mod = (int)1e9 + 7;

void Main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &i : s)
        cin >> i;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i{n}; i >= 1; i--)
    {
        for (int j{n}; j >= 1; j--)
        {
            if (s[i - 1][j - 1] == '*')
                dp[i][j] = 0;
            else if (i == n and j == n)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
        }
    }
    cout << dp[1][1] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    atomic<bool> finished(false);
    freopen("i1.txt", "r", stdin);
    freopen("o1.txt", "w", stdout);
    freopen("e1.txt", "w", stderr);
    auto Beginning = chrono::high_resolution_clock::now();
    auto Termination = [&]() -> void
    {
        auto Conclusion = chrono::high_resolution_clock::now();
        auto Duration = chrono::duration_cast<chrono::microseconds>(Conclusion - Beginning);
        cerr << "Time: " << Duration.count() / 1000.0 << " Microseconds" << endl;
    };
    auto Watcher = [&]() -> void
    {
        this_thread::sleep_for(TimeLimit);
        if (!finished.load())
        {
            Termination();
            cerr << "Execution time exceeded. Terminating program.\n";
            exit(1);
        }
    };
    thread timer(Watcher);
#endif
    int TestCount{1ll};
    if (TestCases)
        cin >> TestCount;
    while (TestCount--)
        Main();
#ifndef ONLINE_JUDGE
    Termination();
    finished.store(true);
    timer.join();
#endif
    return 0;
}