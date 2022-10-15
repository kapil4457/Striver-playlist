//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // Function to find the number of islands.
    vector<int> drow{0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> dcol{1, 1, 0, -1, -1, -1, 0, 1};
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return;
        }
        if (grid[i][j] == '0')
        {
            return;
        }

        if (!vis[i][j])
        {
            vis[i][j] = true;
            for (int k = 0; k < 8; ++k)
            {
                dfs(grid, vis, i + drow[k], j + dcol[k]);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // no of disconnected components

        int island = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && grid[i][j] != '0')
                {
                    dfs(grid, vis, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends