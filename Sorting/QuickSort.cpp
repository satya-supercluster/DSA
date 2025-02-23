// Time Complexity:- Average case O(nlog(n)), Worst Case O(N2)
// Space Complexity:- Average case O(log(n)), Worst Case O(N)


// 1. Pick a Pivot && place it in its correct place in the sorted array. 
//      (smaller in left, greater in right)
// 2. to place the pivot follow ->
//     a. i=low,j=hight
//     b.  while i<j
//              while (arr[i] <= arr[pivot] and i<=high) i++
//              while (arr[i] > arr[pivot] and j>=low) j--
//              if(i<j)
//                   swap arr[i] and arr[j]
//     c. swap arr[pivot] and arr[j]
//     d. return j;


#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// TODO: Code Here

int sort(vector<int> &v,int low,int high){
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

void quickSort(vector<int> &v,int low,int high){
    if(low<high){
        int pivot = sort(v,low,high);
        quickSort(v,low,pivot-1);
        quickSort(v,pivot+1,high);
    }
}


int Main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&i:v) cin>>i;
    quickSort(v,0,n-1);
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