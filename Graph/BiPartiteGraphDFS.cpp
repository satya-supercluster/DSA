#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// Code Here:

bool dfs(int u, vector<int>&color,vector<vector<int>>&adj){
    for(auto&child:adj[u]){
        if(color[child]==-1){
            color[child]=1-color[u];
            if(!dfs(child,color,adj)){
                return false;
            }
        }
        else if(color[child]==color[u]) return false;
    }
    return true;
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
    vector<int> color(n+1,-1);
    for(int i{1};i<=n;i++){
        if(color[i]==-1){
            color[i]=0;
            if(!dfs(i,color,adj)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;

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