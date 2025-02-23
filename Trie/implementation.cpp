#include<bits/stdc++.h>
using namespace std;
constexpr chrono::seconds TimeLimit = 3s;

// Code Here:

struct node{
    vector<node*> children;
    bool EOW;
    node() : children(26, nullptr), EOW(false) {}
};

class Trie{
private:
    node*root;
    public:
    Trie() : root(new node()) {}
    void add(string s){
        node*p=root;
        for(auto&i:s){
            if(!(p->children[i-'a'])){
                p->children[i-'a'] = new node();
                p=p->children[i-'a'];
            }
            else{
                p=p->children[i-'a'];
            }
        }
        p->EOW=true;
    }
    bool find(string s){
        node*p=root;
        for(auto&i:s){
            if(!p){
                return false;
            }
            else if(!(p->children[i-'a'])) return false;
            else p=p->children[i-'a'];
        }
        return p->EOW;
    }
};

int Main() {
    Trie trie;
    trie.add("hello");
    trie.add("world");
    cout << "Find 'hello': " << trie.find("hello") << endl;
    cout << "Find 'world': " << trie.find("world") << endl;
    cout << "Find 'helloworld': " << trie.find("helloworld") << endl;
    cout << "Find 'hell': " << trie.find("hell") << endl;

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