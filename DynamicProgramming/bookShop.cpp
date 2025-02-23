#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <satya/seeBug.h>
#else
#define debug(...) "SATYA.AKEA";
#endif
#define ll long long int
#define endl "\n"
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
#define elif else if
#define eb emplace_back
#define ff first
#define ss second
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> inline istream &operator>>(istream &cin, vector<T> &a){ for (T &x : a) cin >> x; return cin; }
template <typename T> inline ostream &operator<<(ostream &out, vector<T> &a) { for (T &x : a) out << x<<" "; return out; }
constexpr chrono::seconds TimeLimit = 3s;
static const bool TestCases = false;
static const int mod = (int)1e9+7;



void Main()
{
    int n,k;
    cin>>n>>k;
    vi rs(n),pg(n);
    cin>>rs>>pg;
    vc<vi>dp(n+1,vi(k+1,0));
    for(int i{1};i<=n;i++){
        for(int j{1};j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j>rs[i-1]) dp[i][j]=max(dp[i][j],pg[i-1]+dp[i][j-rs[i-1]]);
        }
    }
    debug(dp);
    cout<<dp[n][k]<<endl;

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
    for(int i{1};i<=TestCount;i++){
#ifndef ONLINE_JUDGE
        cerr<<"Test Case #"<<i<<":"<<endl;
#endif
        Main();
    }
#ifndef ONLINE_JUDGE
    Termination(); finished.store(true); timer.join();
#endif
    return 0;
}