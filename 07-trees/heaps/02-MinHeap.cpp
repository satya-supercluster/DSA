#include<bits/stdc++.h>
using namespace std;

class MinHeap{
private:
    vector<int> arr;
public:
    MinHeap(){}
    MinHeap(vector<int>&v): arr(v){heapify();}
    void heapifyHelper(int i){
        int l=2*i+1, r=2*i+2;
        int smallest=i;
        if(l<arr.size() and arr[l]<arr[smallest]) smallest = l;
        if(r<arr.size() and arr[r]<arr[smallest]) smallest = r;
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            heapifyHelper(smallest);
        }
    }
    void heapify(){
        for(int i{(int)arr.size() / 2 - 1}; i>=0; i--){
            heapifyHelper(i);
        }
    }
    void print(){
        for(auto&i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    bool isEmpty(){
        return arr.size()==0;
    }
    int peek(){
        if(isEmpty()) return -1;
        int top=arr[0];
        swap(arr[0],arr.back());
        arr.pop_back();
        heapifyHelper(0);
        return top;
    }
    void insert(int x){
        arr.push_back(x);
        int ind=arr.size()-1;
        while(ind>0){
            int par = (ind-1)/2;
            if(arr[par]>arr[ind]){
                swap(arr[par],arr[ind]);
            }
            else{
                break;
            }
            ind=par;
        }
    }
};


int main()
{
    // Test 1: Basic heapify
    vector<int> v{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    MinHeap mh(v);
    cout << "Heap after heapify: ";
    mh.print();

    // Test 2: Peek (extract Min)
    cout << "Extracted Min: " << mh.peek() << endl;
    cout << "Heap after extracting Min: ";
    mh.print();

    // Test 3: Extract all elements
    cout << "Extracting all elements: ";
    while (!mh.isEmpty())
    {
        cout << mh.peek() << " ";
    }
    cout << endl;
    
    // Test 3.5: Insertion
    MinHeap heapInsertTest;
    heapInsertTest.insert(10);
    heapInsertTest.insert(4);
    heapInsertTest.insert(15);
    heapInsertTest.insert(1);
    cout << "Heap after insertions (should be min-heap): ";
    heapInsertTest.print();
    // Expected output: 1 4 15 10 (or any valid min-heap order)

    // Test 4: Empty heap
    MinHeap empty;
    cout << "Peek on empty heap: " << empty.peek() << endl;
    // Expected output: -1

    return 0;
}