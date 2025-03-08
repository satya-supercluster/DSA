// Given a string s, your task is to find the longest palindromic substring within s.

#include<bits/stdc++.h>
#include<satya/seebug.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// Code Here:

string longestPalindrome(string &s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i{}; i < n; i++)
    {
        dp[i][i] = 1;
    }
    int ans{};
    pair<int, int> pi;
    for (int j{}; j < n; j++)
    {
        for (int i{j-1}; i >= 0; i--)
        {
            if (s[i] == s[j] and (dp[i + 1][j - 1] or j-i==1))
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
                if (ans < dp[i][j])
                {
                    ans = dp[i][j];
                    pi = {i, j};
                }
            }
        }
    }
    debug(dp);
    string str;
    if (ans)
    {
        for (int i{pi.first}; i <= pi.second; i++)
        {
            str.push_back(s[i]);
        }
    }
    else
        str.push_back(s[0]);
    return str;
}

int Main(){

    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;

    return 0;
}



// IGNORE_IT
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    atomic<bool> finished(false);
    freopen("C:/Users/Satyam Gupta/Desktop/DSA/input.txt", "r", stdin);
    freopen("C:/Users/Satyam Gupta/Desktop/DSA/output.txt", "w", stdout);
    freopen("C:/Users/Satyam Gupta/Desktop/DSA/error.txt", "w", stderr);
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
    Main();
#ifndef ONLINE_JUDGE
    Termination();
    finished.store(true);
    timer.join();
#endif
    return 0;
}