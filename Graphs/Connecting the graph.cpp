//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


//Approach
// Step 1 : Count the number og components
// Steps 2 : Count the total number of extra edges
// Step 3 : If this count is greater than number of components - 1 , we return (n-1)  else -1

// To find this count we apply disjoint set on each components

class DisjointSet{

    public:

        vector<int>rank,parent;

        DisjointSet(int n){

            rank.resize(n+1,0);

            parent.resize(n+1);

            for(int i=0;i<n;i++){

                parent[i]=i;

            }

        }

        int findUParent(int node){

            if(node==parent[node])return node;

            return parent[node]=findUParent(parent[node]);

        }

        void unionR(int u,int v){

            int up_u=findUParent(u);

            int up_v=findUParent(v);

            if(up_u==up_v)return;

            if(rank[up_u]>rank[up_v]){

                parent[up_v]=up_u;

            }

            else if(rank[up_v]>rank[up_u]){

                parent[up_u]=up_v;

            }

            else{

                parent[up_v]=up_u;

                rank[up_u]++;

            }

        }

};

class Solution {

  public:

    int Solve(int n, vector<vector<int>>& edge){

        // code here

        DisjointSet ds(n);

        int xtraC=0;

        for(auto it:edge){

            int u=it[0];

            int v=it[1];

            if(ds.findUParent(u)==ds.findUParent(v)){

                xtraC++;

            }

            else{

                ds.unionR(u,v);

            }

        }

        int cnt=0;

        for(int i=0;i<n;i++){

            if(ds.parent[i]==i)cnt++;

        }

        int ans=cnt-1;

        if(xtraC>=ans)return ans;

        return -1;

    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends