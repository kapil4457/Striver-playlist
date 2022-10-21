//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfsvisited)
    {
        visited[node] = 1;
        dfsvisited[node] = 1;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, dfsvisited))
                    return true;
            }
            else if (dfsvisited[i])
            {
                return true;
            }
        }

        dfsvisited[node] = false;
        return false;
    }

public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        int p = prerequisites.size();
        vector<int> adj[N];
        for (int i = 0; i < p; i++)
        {
            int u = prerequisites[i].second;
            int v = prerequisites[i].first;

            adj[u].push_back(v);
        }

        vector<int> visited(N, 0);
        vector<int> dfsvisited(N, 0);
        bool isCycle = 0;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, dfsvisited))
                {
                    isCycle = 1;
                    break;
                }
            }
        }

        if (isCycle)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends