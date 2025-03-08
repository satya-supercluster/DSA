// You are given two strings s1 and s2.Your task is to find the length of the longest common substring among the given strings.

#include <bits/stdc++.h>
using namespace std;

// Code Here:

string longestCommon(string&a,string&b){
    
}



void Main(){
    string a,b;
    cin>>a>>b;
    string s=longestCommon(a,b);
    cout<<s<<endl;
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
