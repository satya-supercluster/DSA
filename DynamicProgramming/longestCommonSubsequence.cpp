#include <bits/stdc++.h>
#include<satya/seebug.h>
using namespace std;

// Code Here:

// Simple Recursion
string find(string&a,string&b,int ai,int bi){
    int n=a.length(),m=b.length();
    if(ai>=n or bi>=m) return "";
    if(a[ai]==b[bi]) return a[ai]+find(a,b,ai+1,bi+1);
    string s1 = find(a, b, ai, bi + 1);
    string s2 = find(a, b, ai + 1, bi);
    if(s1.length()>=s2.length()) return s1;
    return s2;
}

// Memoization
string find(string &a, string &b, vector<vector<string>> &dp,int ai, int bi)
{
    int n=a.length(),m=b.length();
    if(ai>=n or bi>=m) return "";
    if(dp[ai][bi].length()!=0) return dp[ai][bi];
    if(a[ai]==b[bi]) return dp[ai][bi] = string(1,a[ai])+find(a,b,dp,ai+1,bi+1);
    string s1 = find(a, b, dp, ai, bi + 1);
    string s2 = find(a, b, dp, ai + 1, bi);
    if (s1.length() >= s2.length()) return dp[ai][bi] = s1;
    return dp[ai][bi] = s2;
}

string longestCommon(string&a,string&b){
    vector<vector<string>>dp(a.length(),vector<string>(b.length(),""));
    find(a, b, dp, 0, 0);
    debug(dp);
    return dp[0][0];
}

void Main(){
    string a,b;
    cin>>a>>b;
    cout<<longestCommon(a,b)<<endl;

    // Tabulation
    int n = a.length(), m = b.length();
    vector<vector<string>> dp(a.length()+1, vector<string>(b.length()+1, ""));
    for(int i{1};i<=n;i++){
        for(int j{1};j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=a[i-1]+dp[i-1][j-1];
            }
            else if(dp[i-1][j].length()>=dp[i][j-1].length()) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i][j-1];
        }
    }
    debug(dp);
    string ans=dp[n][m];
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
