//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detect(int node, vector<int> adj[], int vis[], int parent)
    {
        if (vis[node])
        {
            return true;
        }

        vis[node] = 1;

        for (auto it : adj[node])
        {

            if (!vis[it])
            {

                if (detect(it, adj, vis, node))
                    return true;
            }
            else if (it != parent)
                return true;
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {

            if (vis[i] == 0)
            {

                if (detect(i, adj, vis, -1))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends