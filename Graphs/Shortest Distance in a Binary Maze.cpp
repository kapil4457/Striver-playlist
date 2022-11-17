//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[src.first][src.second] = 0;
        q.push({0, src});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            if (r == dest.first && c == dest.second)
                return d;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 0 && 1 + d < dist[nr][nc])
                {
                    dist[nr][nc] = 1 + d;
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends