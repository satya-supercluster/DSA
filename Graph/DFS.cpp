#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// Code Here:

void dfs(int u,vector<int>&vis,vector<vector<int>>&adj){
    vis[u]=1;
    cout<<u<<" ";
    for(auto&child:adj[u]){
        if(!vis[child]){
            dfs(child,vis,adj);
        }
    }
}


int Main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i{};i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    for(int i{1};i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,adj);
        }
    }

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