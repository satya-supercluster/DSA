#include<bits/stdc++.h>
using namespace std;

class Interval{
    double start,end;
public:
    Interval(int s, int e):start(s),end(e){}
    Interval(){start=-1; end=-1;}
    bool isValid(){
        return start<=end;
    }
    bool canMerge(const Interval &other){
        if(!isValid()) return false;
        return max(start, other.start) <= min(end, other.end);
    }
    Interval merge(const Interval &other){
        if(!canMerge(other)) throw invalid_argument("Cannot merge intervals");
        Interval newInterval(min(start,other.start),max(end,other.end));
        return newInterval;
    }
    double midPoint(){
        if(!isValid()) throw invalid_argument("Invalid Interval");
        return (start + end) / 2;
    }
    void print() const {
        cout << "[" << start << ", " << end << "]";
    }
};
int main()
{
    cout << boolalpha;

    Interval A(1, 5), B(3, 7);
    cout << "A can merge B? " << A.canMerge(B) << "\n";
    Interval C = A.merge(B);
    cout << "Merged interval: ";
    C.print();
    cout << "\n";
    cout << "Midpoint of merged: " << C.midPoint() << "\n";

    Interval bad(5, 2);
    try
    {
        cout << "bad valid? " << bad.isValid() << "\n";
        cout << "Midpoint of bad: " << bad.midPoint() << "\n"; // throws
    }
    catch (const invalid_argument &e)
    {
        cout << "Exception: " << e.what() << "\n";
    }

    Interval D(1, 3), E(5, 8);
    try
    {
        Interval F = D.merge(E); // throws
        F.print();
    }
    catch (const invalid_argument &e)
    {
        cout << "Exception: " << e.what() << "\n";
    }
}