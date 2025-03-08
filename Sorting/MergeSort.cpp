// Time Complexity O(nlog(n))
// Space Complexity O(n)

#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// Code Here:


void merge(vector<int>&v,int low,int mid,int high){
    int i=low,j=mid+1;
    vector<int> extraSpace;
    while(i<=mid and j<=high){
        if(v[i]==v[j]){
            extraSpace.push_back(v[i++]);
            extraSpace.push_back(v[j++]);
        }
        else if(v[i]<v[j]) extraSpace.push_back(v[i++]);
        else extraSpace.push_back(v[j++]);
    }
    while(i<=mid) extraSpace.push_back(v[i++]);
    while(j<=high) extraSpace.push_back(v[j++]);
    for(int i{low};i<=high;i++){
        v[i]=extraSpace[i-low];
    }
}

void mergeSort(vector<int>&v,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        merge(v,low,mid,high);
    }
}

int Main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&i:v) cin>>i;
    mergeSort(v,0,n-1);
    for(auto&i:v) cout<<i<<" ";
    cout<<endl;
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