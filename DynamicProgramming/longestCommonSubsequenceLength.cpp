#include <bits/stdc++.h>
using namespace std;

// Code Here:

// Simple Recursion
int find(string&a,string&b,int ai,int bi){
    int n=a.length(),m=b.length();
    if(ai>=n or bi>=m) return 0;
    if(a[ai]==b[bi]) return 1+find(a,b,ai+1,bi+1);
    return max(find(a,b,ai,bi+1),find(a,b,ai+1,bi));
}

// Memoization
int find(string &a, string &b, vector<vector<int>> &dp,int ai, int bi)
{
    int n=a.length(),m=b.length();
    if(ai>=n or bi>=m) return 0;
    if(dp[ai][bi]!=-1) return dp[ai][bi];
    if(a[ai]==b[bi]) return dp[ai][bi]=1+find(a,b,dp,ai+1,bi+1);
    return dp[ai][bi]=max(find(a,b,dp,ai,bi+1),find(a,b,dp,ai+1,bi));
}

int longestCommon(string&a,string&b){
    vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
    return find(a,b,dp,0,0);
}

void Main(){
    string a,b;
    cin>>a>>b;
    cout<<longestCommon(a,b)<<endl;

    // Tabulation
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
    for(int i{1};i<=n;i++){
        for(int j{1};j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
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
