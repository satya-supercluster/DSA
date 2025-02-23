#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <satya/seeBug.h>
#else
#define debug(...) "SATYA.AKEA";
#endif
#define ll long long int
#define endl "\n"
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;
const bool TestCases = false;


void Main()
{
    int n,k;
    cin>>n>>k;
    vector<int>c(n);
    for(auto&i:c)cin>>i;
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    for(int i{1};i<=k;i++)dp[0][i]=1e9;
    for(int i{1};i<=n;i++){
        for(int j{1};j<=k;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=c[i-1])
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - c[i - 1]]);
        }
    }
    if(dp[n][k]!=1e9)
    cout<<dp[n][k]<<endl;
    else cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    atomic<bool> finished(false);
    freopen("i1.txt", "r", stdin); freopen("o1.txt", "w", stdout); freopen("e1.txt", "w", stderr);
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
    int TestCount{1ll}; if (TestCases) cin >> TestCount;
    while(TestCount--) Main();
#ifndef ONLINE_JUDGE
    Termination(); finished.store(true); timer.join();
#endif
    return 0;
}