#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> arr;

public:
    MaxHeap() {}
    MaxHeap(vector<int> &v) : arr(v) { heapify(); }
    void heapify_helper(int i)
    {
        int l{2 * i + 1}, r{2 * i + 2};
        int largest = i;
        if (l < arr.size() and arr[largest] < arr[l])
            largest = l;
        if (r < arr.size() and arr[largest] < arr[r])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify_helper(largest);
        }
    }
    void heapify()
    {
        for (int i{(int)arr.size() / 2}; i >= 0; i--)
        {
            heapify_helper(i);
        }
    }
    int peek()
    {
        if (arr.size() == 0)
            return -1;
        int top = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapify_helper(0);
        return top;
    }
    void print()
    {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
    bool isEmpty()
    {
        return arr.size() == 0;
    }
};

void heapSort(vector<int> &v)
{
    MaxHeap mxh(v);
    vector<int> ans;
    while(!mxh.isEmpty()){
        ans.push_back(mxh.peek());
    }
    reverse(ans.begin(),ans.end());
    v=ans;
}

int main()
{
    // Test 1: Basic heapify
    vector<int> v{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    heapSort(v);
    for(auto&i:v) cout<<i<<" ";
    cout<<endl;
    
    MaxHeap mh(v);
    cout << "Heap after heapify: ";
    mh.print();

    // Test 2: Peek (extract max)
    cout << "Extracted max: " << mh.peek() << endl;
    cout << "Heap after extracting max: ";
    mh.print();

    // Test 3: Extract all elements
    cout << "Extracting all elements: ";
    while (!mh.isEmpty())
    {
        cout << mh.peek() << " ";
    }
    cout << endl;

    // Test 4: Empty heap
    MaxHeap empty;
    cout << "Peek on empty heap: " << empty.peek() << endl;
    // Expected output: -1

    return 0;
}