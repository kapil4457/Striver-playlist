

// Time Complexity : O(N) + O(V+2E)
// Space Complexity : O(N)+O(N)
class Solution
{
private:
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;

        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // Creating the adjacency list
        vector<int> adjLs[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && adj[i][j] == 1)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        // Starting the traversal
        int vis[V] = {0};

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {

            if (!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};