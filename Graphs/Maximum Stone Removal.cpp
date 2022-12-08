//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class disjointSet
{
    public:
    vector<int> rank , parent , size;
    disjointSet(int n)
    {
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1 , 1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    int ultimateParent(int x)
    {
        if(x == parent[x])
        {
            return x;
        }
        parent[x] = ultimateParent(parent[x]);
        return parent[x];
    }
    void unionBySize(int u, int v)
    {
        int ultpar_u = ultimateParent(u);
        int ultpar_v = ultimateParent(v);
        if(ultpar_u == ultpar_v) return;
        if(size[ultpar_u] < size[ultpar_v])
        {
            parent[ultpar_u] = ultpar_v;
            size[ultpar_v] += size[ultpar_u];
        }
        else
        {
            parent[ultpar_v] = ultpar_u;
            size[ultpar_u] += size[ultpar_v];
        }
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n)
    {
        int maxrow = 0;
        int maxcol = 0;
        for(auto it : stones)
        {
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol , it[1]);
        }
        
        disjointSet ds(maxrow + maxcol + 1);
        
        for(auto it : stones)
        {
            int noderow = it[0];
            int nodecol = maxrow+it[1]+1;
            ds.unionBySize(noderow , nodecol);
        }
        
        int comp = 0;
        int x = ds.parent.size();
        for(int i=0;i<=x;i++)
        {
            if(ds.parent[i] == i && ds.size[i] > 1)
            {
                comp++;
            }
        }
        return n-comp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends