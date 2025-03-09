// You are given two strings s1 and s2.Your task is to find the length of the longest common substring among the given strings.

#include <bits/stdc++.h>
using namespace std;

// Code Here:

void Main(){
    string a,b;
    cin>>a>>b;

    // Tabulation
    int n=a.length(),m=b.length();
    int mx{-1},ind{-1};

    // Using pair<int,int> to store first index
    // vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(m+1,{0,-1}));
    // for(int i{1};i<=n;i++){
    //     for(int j{1};j<=m;j++){
    //         if(a[i-1]==b[j-1]){
    //             if(dp[i-1][j-1].first!=0){
    //                 dp[i][j].first = 1 + dp[i-1][j-1].first;
    //                 dp[i][j].second = dp[i-1][j-1].second;
    //             }
    //             else {
    //                 dp[i][j] = {1,i-1};
    //             }
    //             if(mx<dp[i][j].first){
    //                 mx=dp[i][j].first;
    //                 ind=dp[i][j].second;
    //             }
    //         }
    //     }
    // }
    // for (int i{ind}; i < ind + mx; i++)
    // {
    //     cout << a[i];
    // }
    // cout << endl;

    // Without that
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i{1};i<=n;i++){
        for(int j{1};j<=m;j++){
            if(a[i-1]==b[j-1]){
                if(dp[i-1][j-1]!=0){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1;
                }
                if(mx<dp[i][j]){
                    mx=dp[i][j];
                    ind = i-1;
                }
            }
        }
    }
    string ans;
    for(int i{ind};i>ind-mx;i--){
        ans.push_back(a[i]);
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

// Ignore It
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("C:/Users/Satyam Gupta/Desktop/DSA/input.txt", "r", stdin);
    freopen("C:/Users/Satyam Gupta/Desktop/DSA/output.txt", "w", stdout);
    freopen("C:/Users/Satyam Gupta/Desktop/DSA/error.txt", "w", stderr);
    atomic<bool> f(false);
    thread t([&](){ this_thread::sleep_for(1s); if(!f.load()) exit(1); });
    Main(); f.store(true); t.join();
    return 0;
}
