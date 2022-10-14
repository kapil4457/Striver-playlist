class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto ele : adj[node])
            {
                if (vis[ele] != 1)
                {
                    vis[ele] = 1;
                    q.push(ele);
                }
            }
        }

        return bfs;
    }
};