//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        vector<pair<int, int>> adj[n];

        for (auto r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n, 1e9), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;

        pq.push({0, 0}); //{dist, node}

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int currnode = curr.second;
            int currdist = curr.first;

            for (auto nei : adj[currnode])
            {
                if (dist[nei.first] >= currdist + nei.second)
                {
                    if (dist[nei.first] == currdist + nei.second)
                    {
                        ways[nei.first] = (ways[nei.first] + ways[currnode]) % mod;
                    }
                    else
                    {
                        ways[nei.first] = ways[currnode];
                        dist[nei.first] = (currdist + nei.second) % mod;
                        pq.push({dist[nei.first], nei.first});
                    }
                }
            }
        }

        return ways[n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends