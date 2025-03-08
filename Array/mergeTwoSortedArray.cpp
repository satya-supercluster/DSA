#include <bits/stdc++.h>
using namespace std;

// Code Here:

// WithoutExtraSpace ---> GAP Method
void mergeWithoutExtraSpace(vector<int> &v, int low, int mid, int high)
{
    int n=mid-low+1,m=high-mid;
    int gap=(n+m+1)/2; // ceil-mid
    while(1){
        for(int i{low+gap};i<high;i++){
            if(v[i-gap]>v[i]) swap(v[i],v[i-gap]);
        }
        if(gap==1) break;
        gap=(gap+1)/2; // ceil-mid
    }
}

// WithoutExtraSpaceUsingSort
void mergeWithoutExtraSpaceUsingSort(vector<int> &v, int low, int mid, int high)
{
    int i=mid,j=mid+1;
    while (i >= low and j <= high and v[i] > v[j])
    {
        swap(v[i],v[j]);
        i--;j++;
    }
    sort(v.begin()+low,v.begin()+mid+1);
    sort(v.begin()+mid+1,v.begin()+high+1);
}

// WithExtraSpace
void mergeWithExtraSpace(vector<int>&v,int low,int mid,int high){
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
        mergeWithoutExtraSpaceUsingSort(v,low,mid,high);
    }
}

void Main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    mergeSort(v, 0, n - 1);
    for (auto &i : v) cout << i << " ";
    cout << endl;
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
