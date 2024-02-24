/* 
    Class for implementing Disjoint Set Union (DSU) Data Structure using both rank and size based union strategies.

    A DSU can help us answer a query such as: "Do nodes u and v lie in the same component?" in constant time.

    It is mostly employed for usage in Dynamic Graphs (i.e. graphs which change their nature with time).
*/

#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
class DSU {
    vector<int> size,parent;
    public:
    DSU(int n) {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findPar(int node) {
        return parent[node]=node==parent[node]?node:findPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu=findPar(u),pv=findPar(v);
        if(pu<pv) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
