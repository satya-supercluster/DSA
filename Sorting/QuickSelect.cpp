// Find the kth largest element in an array
// kth largest means it is indexed n-k
// apply quick sort to find value at n-k index

#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// TODO: Code Here


int quickSelect(vector<int> &v,int low,int high){
    int pivot=low;
    int i=low,j=high;
    while(i<j){
        while(i<=high and v[i]<=v[pivot]) i++;
        while(j>=low and v[j]>v[pivot]) j--;
        if(i<j) swap(v[i],v[j]);
    }
    if(j>=low) swap(v[pivot],v[j]);
    return j;
}

int findKthLargest(vector<int>&v,int low, int high,int n,int k){
    int ans{-1};
    if(low<high){
        int pivot=quickSelect(v,low,high);
        if(pivot==n-k){
            return v[pivot];
        }
        else if(pivot>n-k){
            ans=findKthLargest(v, low, pivot - 1,n,k);
        }
        else
            ans=findKthLargest(v, pivot + 1, high, n, k);
    }
    return ans;
}


int Main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&i:v) cin>>i;
    int k;
    cin>>k;
    int kthLargest=findKthLargest(v,0,n-1,n,k);
    cout<<k<<"th largest element: "<<kthLargest<<endl;

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