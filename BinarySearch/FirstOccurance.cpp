#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// TODO: Code Here

int binary_search(vector<int>&v,int n,int val){
    int start=0,end=n-1,mid,ans{-1};
    while(start<=end){
        mid=start+(end-start)/2;
        if(v[mid]==val)
        {
            if (ans == -1) ans = mid;
            else ans = min(ans, mid);
            end=mid-1;
        }
        else if(v[mid]<val) start=mid+1;
        else end=mid-1;
    }
    return ans;
}


int Main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&i:v) cin>>i;
    int val;
    cin>>val;
    int ind = binary_search(v, n, val) ;
    if (ind!=-1)
    {
        cout<<"Found at index: "<<ind<<endl;
    }
    else cout<<"Not Found"<<endl;

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