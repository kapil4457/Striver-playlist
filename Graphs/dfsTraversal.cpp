// Time Compelxity : O(N + 2E)
//  Space Compelxity : O(N)

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &lis)
    {
        vis[node] = 1;
        lis.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, lis);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};