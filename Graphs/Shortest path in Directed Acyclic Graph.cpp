//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
private:
    void dfs(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &topo)
    {
        vis[node] = 1;
        for (auto &it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                dfs(v, vis, adj, topo);
            }
        }
        topo.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }
        stack<int> topo;
        int vis[N] = {};
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, topo);
            }
        }
        vector<int> dist(N, -1);
        dist[0] = 0;
        while (!topo.empty())
        {
            int node = topo.top();
            topo.pop();
            if (dist[node] == -1)
                continue;
            for (auto &it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dist[v] == -1 or dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends