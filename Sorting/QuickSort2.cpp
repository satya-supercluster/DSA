#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// TODO: Code Here

int sort(vector<int> &v, int low, int high)
{
    int pivot = low;
    int count = 0;
    for(auto i : v){
        if(i<=v[low]){
            count++;
        }
    }
    swap(v[count-1],v[low]);
    int i = low, j = high;
    while (i < j)
    {
        while (v[i] <= v[count-1])
            i++;
        while ( v[j] > v[count-1])
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    return count-1;
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