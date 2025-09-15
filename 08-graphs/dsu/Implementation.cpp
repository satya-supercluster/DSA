#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> parent,rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i{};i<=n;i++) parent[i]=i;
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u]);
    }
    int unionPair(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionPair(1,2);
    ds.unionPair(2,3);
    ds.unionPair(4,5);
    ds.unionPair(6,7);
    ds.unionPair(5,6);

    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"Same component"<<endl;
    }
    else{
        cout<<"Different component"<<endl;
    }

    for(int i{1};i<=7;i++){
        cout<<i<<" -> "<<ds.findParent(i)<<endl;
    }



    ds.unionPair(3,7);
    
    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"Same component"<<endl;
    }
    else{
        cout<<"Different component"<<endl;
    }

    for(int i{1};i<=7;i++){
        cout<<i<<" -> "<<ds.findParent(i)<<endl;
    }

    return 0;
}